/*
 * MT6765 Hawaii Audio Driver
 */

#include <linux/module.h>
#include <linux/of.h>
#include <sound/soc.h>
#include <sound/pcm.h>
#include <sound/pcm_params.h>

static const struct snd_soc_dapm_widget mt6765_hawaii_widgets[] = {
    SND_SOC_DAPM_SPK("Speaker", NULL),
    SND_SOC_DAPM_MIC("Headset Mic", NULL),
    SND_SOC_DAPM_MIC("Main Mic", NULL),
};

static const struct snd_soc_dapm_route mt6765_hawaii_routes[] = {
    {"Speaker", NULL, "SPK"},
    {"Headset Mic", NULL, "HSMIC"},
    {"Main Mic", NULL, "MAINMIC"},
};

static int mt6765_hawaii_hw_params(struct snd_pcm_substream *substream,
                                 struct snd_pcm_hw_params *params)
{
    struct snd_soc_pcm_runtime *rtd = substream->private_data;
    struct snd_soc_dai *codec_dai = rtd->codec_dai;
    int ret;

    ret = snd_soc_dai_set_fmt(codec_dai, SND_SOC_DAIFMT_I2S |
                             SND_SOC_DAIFMT_NB_NF |
                             SND_SOC_DAIFMT_CBS_CFS);
    if (ret)
        return ret;

    return 0;
}

static struct snd_soc_ops mt6765_hawaii_ops = {
    .hw_params = mt6765_hawaii_hw_params,
};

static struct snd_soc_card mt6765_hawaii_card = {
    .name = "MT6765-Hawaii",
    .owner = THIS_MODULE,
    .widgets = mt6765_hawaii_widgets,
    .num_widgets = ARRAY_SIZE(mt6765_hawaii_widgets),
    .dapm_routes = mt6765_hawaii_routes,
    .num_dapm_routes = ARRAY_SIZE(mt6765_hawaii_routes),
    .dai_link = &mt6765_hawaii_dai_links[0],
    .num_links = 1,
};

static int mt6765_hawaii_probe(struct platform_device *pdev)
{
    struct snd_soc_card *card = &mt6765_hawaii_card;
    int ret;

    card->dev = &pdev->dev;
    ret = devm_snd_soc_register_card(&pdev->dev, card);
    if (ret)
        dev_err(&pdev->dev, "snd_soc_register_card failed: %d\n", ret);

    return ret;
}

static const struct of_device_id mt6765_hawaii_dt_match[] = {
    { .compatible = "mediatek,mt6765-hawaii-audio", },
    { }
};

static struct platform_driver mt6765_hawaii_driver = {
    .driver = {
        .name = "mt6765-hawaii",
        .owner = THIS_MODULE,
        .of_match_table = mt6765_hawaii_dt_match,
    },
    .probe = mt6765_hawaii_probe,
};

module_platform_driver(mt6765_hawaii_driver);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MrKernel");
MODULE_DESCRIPTION("MT6765 Hawaii Audio Driver"); 
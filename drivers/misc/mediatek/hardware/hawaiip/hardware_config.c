/*
 * Hawaii+ Hardware Configuration Driver
 */

#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include "hawaiip_config.h"

struct hawaiip_hw_config {
    u32 cpu_max_freq;
    u32 gpu_max_freq;
    u32 display_fps;
    u32 battery_capacity;
};

static struct hawaiip_hw_config hw_config = {
    .cpu_max_freq = 2300000,
    .gpu_max_freq = 950000,
    .display_fps = 90,
    .battery_capacity = 5000,
};

static int hawaiip_hw_probe(struct platform_device *pdev)
{
    struct device_node *node = pdev->dev.of_node;
    
    if (of_property_read_u32(node, "cpu-max-freq", &hw_config.cpu_max_freq))
        dev_warn(&pdev->dev, "Using default CPU max frequency\n");
        
    if (of_property_read_u32(node, "gpu-max-freq", &hw_config.gpu_max_freq))
        dev_warn(&pdev->dev, "Using default GPU max frequency\n");
        
    return 0;
}

static const struct of_device_id hawaiip_hw_of_match[] = {
    { .compatible = "motorola,hawaiip-hw" },
    { }
};

static struct platform_driver hawaiip_hw_driver = {
    .probe = hawaiip_hw_probe,
    .driver = {
        .name = "hawaiip-hw",
        .of_match_table = hawaiip_hw_of_match,
    },
};

module_platform_driver(hawaiip_hw_driver);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MrKernel");
MODULE_DESCRIPTION("Hawaii+ Hardware Configuration Driver"); 
/*
 * Platform-specific setup for Mali G37 GPU
 */

#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include "mali_kbase_config_platform.h"
#include "mali_kbase.h"

static int platform_init(struct kbase_device *kbdev)
{
    struct device_node *np;

    np = of_find_compatible_node(NULL, NULL, "mediatek,mali-g37");
    if (!np) {
        dev_err(kbdev->dev, "Failed to find mali-g37 node\n");
        return -ENODEV;
    }

    /* Initialize GPU frequency tables */
    kbdev->gpu_freq_khz_min = GPU_FREQ_KHZ_MIN;
    kbdev->gpu_freq_khz_max = GPU_FREQ_KHZ_MAX;

    /* Setup power management callbacks */
    kbdev->pm_callbacks = GPU_POWER_MANAGEMENT_CALLBACKS;

    return 0;
}

static void platform_term(struct kbase_device *kbdev)
{
    /* Cleanup platform-specific resources */
}

struct kbase_platform_funcs_conf platform_funcs = {
    .platform_init_func = platform_init,
    .platform_term_func = platform_term
};

static struct kbase_platform_config hawaii_platform_config = {
    .platform_funcs = &platform_funcs,
    .mem_pool_max_size = GPU_MEM_POOL_MAX_SIZE,
    .mem_pool_alloc_order = GPU_MEM_POOL_ALLOC_ORDER,
};

struct kbase_platform_config *kbase_get_platform_config(void)
{
    return &hawaii_platform_config;
} 
/*
 * Vendor HAL Manager for Project Treble
 */

#include <linux/module.h>
#include <linux/init.h>
#include "vendor_hal_manager.h"

struct vendor_hal_module {
    const char *name;
    int version;
    int (*init)(void);
    void (*cleanup)(void);
};

static struct vendor_hal_module hal_modules[] = {
    {
        .name = "audio.primary.mt6765",
        .version = 1,
        .init = audio_hal_init,
        .cleanup = audio_hal_cleanup,
    },
    {
        .name = "camera.mt6765",
        .version = 1,
        .init = camera_hal_init,
        .cleanup = camera_hal_cleanup,
    },
    /* Add other HAL modules */
};

static int __init hal_manager_init(void)
{
    int i, ret;
    
    for (i = 0; i < ARRAY_SIZE(hal_modules); i++) {
        ret = hal_modules[i].init();
        if (ret)
            pr_err("Failed to initialize %s HAL\n", hal_modules[i].name);
    }
    
    return 0;
}

module_init(hal_manager_init);
MODULE_LICENSE("GPL"); 
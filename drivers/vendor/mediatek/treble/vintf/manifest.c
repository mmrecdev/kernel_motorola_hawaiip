/*
 * VINTF Manifest Implementation
 */

#include <linux/module.h>
#include "vintf_manifest.h"

static const struct vintf_hal_entry hal_entries[] = {
    {
        .name = "android.hardware.audio@7.1",
        .transport = HWBINDER,
        .impl = "audio.primary.mt6765",
    },
    {
        .name = "android.hardware.camera@3.5",
        .transport = HWBINDER,
        .impl = "camera.mt6765",
    },
    {
        .name = "android.hardware.graphics.composer@2.4",
        .transport = HWBINDER,
        .impl = "graphics.mt6765",
    },
    /* Add other HAL interfaces */
};

static struct vintf_manifest manifest = {
    .hal_entries = hal_entries,
    .num_entries = ARRAY_SIZE(hal_entries),
};

int vintf_register_manifest(void)
{
    /* Register manifest with system */
    return register_vintf_manifest(&manifest);
}

EXPORT_SYMBOL_GPL(vintf_register_manifest);
MODULE_LICENSE("GPL"); 
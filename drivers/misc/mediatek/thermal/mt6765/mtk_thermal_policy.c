/*
 * MediaTek Thermal Policy Driver for MT6765 (Helio G37)
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/thermal.h>
#include "mtk_thermal_policy.h"

static int mtk_thermal_get_temp(struct thermal_zone_device *thermal, int *temp)
{
    *temp = get_immediate_cpu_wrap() * 1000;
    return 0;
}

static int mtk_thermal_get_mode(struct thermal_zone_device *thermal,
                              enum thermal_device_mode *mode)
{
    *mode = THERMAL_DEVICE_ENABLED;
    return 0;
}

static int mtk_thermal_set_mode(struct thermal_zone_device *thermal,
                              enum thermal_device_mode mode)
{
    return 0;
}

static int mtk_thermal_get_trip_type(struct thermal_zone_device *thermal,
                                   int trip, enum thermal_trip_type *type)
{
    switch (trip) {
    case 0:
        *type = THERMAL_TRIP_ACTIVE;
        break;
    case 1:
        *type = THERMAL_TRIP_WARNING;
        break;
    case 2:
        *type = THERMAL_TRIP_CRITICAL;
        break;
    default:
        return -EINVAL;
    }
    return 0;
}

static struct thermal_zone_device_ops mtk_thermal_ops = {
    .get_temp = mtk_thermal_get_temp,
    .get_mode = mtk_thermal_get_mode,
    .set_mode = mtk_thermal_set_mode,
    .get_trip_type = mtk_thermal_get_trip_type,
};

static int __init mtk_thermal_init(void)
{
    struct thermal_zone_device *tz;
    
    tz = thermal_zone_device_register("mtk-thermal", CPU_THERMAL_TRIP_NUM, 0,
                                    NULL, &mtk_thermal_ops, NULL, 0, 
                                    thermal_policy.polling_interval);
    if (IS_ERR(tz))
        return PTR_ERR(tz);
        
    return 0;
}

static void __exit mtk_thermal_exit(void)
{
    thermal_zone_device_unregister(thermal_zone);
}

module_init(mtk_thermal_init);
module_exit(mtk_thermal_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("MediaTek Thermal Policy Driver");
MODULE_AUTHOR("MrKernel");
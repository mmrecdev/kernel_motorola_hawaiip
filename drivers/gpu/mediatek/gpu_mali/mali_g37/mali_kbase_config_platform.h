/*
 * Platform configuration for Mediatek MT6765 (Helio G37)
 */

#ifndef _MALI_KBASE_CONFIG_PLATFORM_H_
#define _MALI_KBASE_CONFIG_PLATFORM_H_

/* GPU Frequency tables */
#define GPU_FREQ_KHZ_MAX   950000
#define GPU_FREQ_KHZ_MIN   299000

/* Power Management Configuration */
#define GPU_POWER_MANAGEMENT_CALLBACKS (&pm_callbacks)
#define GPU_PLATFORM_POWER_DOWN_ONLY (1)

/* Thermal Management */
#define GPU_THERMAL_LIMIT_TEMP       95000  /* 95°C */
#define GPU_TEMP_THROTTLING_ENABLE   (1)

/* Memory Configuration */
#define GPU_MEM_POOL_MAX_SIZE       (512 * 1024 * 1024)  /* 512MB */
#define GPU_MEM_POOL_ALLOC_ORDER    (0)

#endif /* _MALI_KBASE_CONFIG_PLATFORM_H_ */ 
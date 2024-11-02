/*
 * Hawaii+ Platform Configuration
 */

#ifndef _HAWAIIP_CONFIG_H
#define _HAWAIIP_CONFIG_H

/* Platform Identification */
#define PLATFORM_NAME "hawaiip"
#define PLATFORM_VERSION "X.X.X"
#define SOC_NAME "mt6765"

/* Memory Configuration */
#define HAWAIIP_MEM_SIZE 0x80000000  /* 2GB */
#define HAWAIIP_MIN_MEM 0x40000000   /* 1GB */

/* Display Configuration */
#define DISPLAY_WIDTH 720
#define DISPLAY_HEIGHT 1600
#define DISPLAY_FPS 90

/* Battery Configuration */
#define BATTERY_CAPACITY 5000  /* mAh */
#define FAST_CHARGE_CURRENT 2000  /* mA */

/* Sensor Configuration */
#define ACCELEROMETER_NAME "LSM6DSM"
#define PROXIMITY_NAME "STK3X3X"

#endif /* _HAWAIIP_CONFIG_H */ 
LOCAL_PATH := $(call my-dir)

# Vendor Init
include $(CLEAR_VARS)
LOCAL_MODULE := vendor_init
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := vendor_init.c
LOCAL_SHARED_LIBRARIES := liblog libcutils
include $(BUILD_SHARED_LIBRARY)

# HAL Manager
include $(CLEAR_VARS)
LOCAL_MODULE := vendor_hal_manager
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := vendor_hal_manager.c
LOCAL_SHARED_LIBRARIES := liblog libcutils
include $(BUILD_SHARED_LIBRARY)

# VINTF Manifest
include $(CLEAR_VARS)
LOCAL_MODULE := vintf_manifest
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := vintf/manifest.c
LOCAL_SHARED_LIBRARIES := liblog libcutils
include $(BUILD_SHARED_LIBRARY) 
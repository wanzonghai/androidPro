LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := ext_hxnet
LOCAL_MODULE_FILENAME := hxnet


APP_DEBUG := $(strip $(NDK_DEBUG))

ifeq ($(APP_DEBUG),1)
	LOCAL_SRC_FILES := $(APP_ABI)/Debug/hxlibnetv3.a
# 	$(warning use debug hxlibnetv3.a )
else
	LOCAL_SRC_FILES := $(APP_ABI)/hxlibnetv3.a
endif

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/../../include

LOCAL_WHOLE_STATIC_LIBRARIES := cpufeatures

ifeq ($(APP_ABI),armeabi-v7a)
    LOCAL_CFLAGS := -DHAVE_NEON=1
endif

include $(PREBUILT_STATIC_LIBRARY)

$(call import-module, android/cpufeatures)

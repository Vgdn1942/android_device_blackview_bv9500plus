LOCAL_PATH := $(call my-dir)

ifneq ($(filter bv9500plus,$(TARGET_DEVICE)),)
include $(call all-makefiles-under,$(LOCAL_PATH))
endif

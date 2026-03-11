#
# Copyright (C) 2024 The TWRP Open Source Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from Infinix-X663 device
$(call inherit-product, device/infinix/Infinix-X663/device.mk)

# Inherit some common TWRP stuff.
$(call inherit-product, vendor/twrp/config/common.mk)

# Product Specifics
PRODUCT_NAME := twrp_X663
PRODUCT_DEVICE := Infinix-X663
PRODUCT_BRAND := Infinix
PRODUCT_MODEL := Infinix X663
PRODUCT_MANUFACTURER := INFINIX

PRODUCT_GMS_CLIENTID_BASE := android-infinix

PRODUCT_BUILD_PROP_OVERRIDES += \
    TARGET_DEVICE=Infinix-X663 \
    PRODUCT_NAME=X663 \
    PRIVATE_BUILD_DESC="X663-user 11 RP1A.200720.011 release-keys"

BUILD_FINGERPRINT := Infinix/X663/Infinix-X663:11/RP1A.200720.011/$(shell date -u +%Y%m%d):user/release-keys

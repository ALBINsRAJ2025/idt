/*
 * Copyright (C) 2024 The TWRP Open Source Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

// FIX #16: Added missing stdio.h include
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <android-base/properties.h>

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

// FIX #18: Removed unused 'using android::base::GetProperty' import
using std::string;

void property_override(const string& prop, const string& value)
{
    auto pi = (prop_info *)__system_property_find(prop.c_str());

    if (pi != nullptr)
        __system_property_update(pi, value.c_str(), value.size());
    else
        __system_property_add(prop.c_str(), prop.size(), value.c_str(), value.size());
}

void vendor_load_properties()
{
    // FIX #15: Fixed double-prefix bug on ro.product.system.* properties.
    // The prop_partitions loop already appends "vendor." / "odm." — mixing
    // "ro.product.system." as a base then iterating produces invalid keys like
    // "ro.product.system.vendor.device". System partition props must be set separately.

    // Set per-partition product properties (covers "", "vendor.", "odm." prefixes)
    const string prop_partitions[] = {"", "vendor.", "odm."};
    for (const string& prefix : prop_partitions) {
        property_override("ro.product." + prefix + "brand",      "Infinix");
        property_override("ro.product." + prefix + "name",       "X663-GL");
        property_override("ro.product." + prefix + "device",     "Infinix-X663");
        property_override("ro.product." + prefix + "model",      "Infinix X663");
        property_override("ro.product." + prefix + "marketname", "Infinix NOTE 11");
    }

    // FIX #15 continued: Set system partition props separately with correct key path
    property_override("ro.product.system.brand",      "Infinix");
    property_override("ro.product.system.name",       "X663-GL");
    property_override("ro.product.system.device",     "Infinix-X663");
    property_override("ro.product.system.model",      "Infinix X663");
    property_override("ro.product.system.marketname", "Infinix NOTE 11");
}

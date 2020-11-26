/*
   Copyright (c) 2014, The Linux Foundation. All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

//#include <sys/mount.h>

#include <android-base/properties.h>
#include "property_service.h"
//#include "vendor_init.h"

namespace android {
namespace init {

using android::init::property_set;

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void property_override_dual(char const system_prop[], char const vendor_prop[],
    char const value[])
{
    property_override(system_prop, value);
    property_override(vendor_prop, value);
}

void vendor_load_properties()
{
    //mkdir("/mnt/phh", 0755);
    //mount("tmpfs", "/mnt/phh", "tmpfs", MS_NOSUID, "mode=0755");
    //mount("/mnt/phh/bv9500plus_libmtk-ril.so", "/vendor/lib64/libmtk-ril.so", nullptr, MS_BIND, nullptr);
    // sed -i -e 's/AT+EAIC=2/AT+EAIC=3/g' /vendor/lib64/libmtk-ril.so
    // fingerprint
    property_override("ro.system.build.fingerprint", "Blackview/BV9500Plus/BV9500Plus:9/PPR1.180610.011/root.20190821.184752:user/release-keys");
    property_override("ro.bootimage.build.fingerprint", "Blackview/BV9500Plus/BV9500Plus:9/PPR1.180610.011/root.20190821.184752:user/release-keys");
    property_override("ro.build.fingerprint", "Blackview/BV9500Plus/BV9500Plus:9/PPR1.180610.011/root.20190821.184752:user/release-keys");
    property_override("ro.build.description", "BV9500Plus-user 9 PPR1.180610.011 root.20190821.184752 release-keys");
    property_override("ro.product.system.device", "BV9500Plus");
    property_override("ro.product.device", "BV9500Plus");
    property_override("ro.product.name", "BV9500Plus");
    property_override_dual("ro.product.system.name", "ro.vendor.product.name", "BV9500Plus");
    property_override("ro.product.brand", "Blackview");
    property_override_dual("ro.system.product.brand", "ro.vendor.product.brand", "Blackview");
    property_override("ro.product.model", "BV9500Plus");
    property_override("ro.product.board", "s62v71c2k_jk_tee");
    property_override("ro.build.product", "BV9500Plus");
    property_override_dual("ro.product.system.model", "ro.vendor.product.model", "BV9500Plus");
    property_override("ro.product.manufacturer", "A-gold");
    property_override("ro.product.system.manufacturer", "A-gold");
    property_override_dual("ro.system.product.manufacturer", "ro.vendor.product.manufacturer", "A-gold");
    property_override("ro.build.version.incremental", "root.20190821.184752");
    property_override("ro.system.build.version.incremental", "root.20190821.184752");
    property_override("ro.build.version.security_patch", "2019-07-05");
    property_override("ro.build.tags", "release-keys");
    property_override("ro.boot.vbmeta.device_state", "locked");
    property_override("ro.boot.verifiedbootstate", "green");
    property_override("ro.boot.flash.locked", "1");
    property_override("ro.boot.veritymode", "enforcing");
    property_override("ro.boot.warranty_bit", "0");
    property_override("ro.warranty_bit", "0");
    property_override("ro.debuggable", "0");
    property_override("ro.secure", "1");
    property_override("ro.build.type", "user");
    property_override("ro.build.selinux", "0");
    property_override("ro.adb.secure", "1");
}

}  // namespace init
}  // namespace android


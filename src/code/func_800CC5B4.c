// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 SurfaceType_GetBgCamIndex(s32, M2C_UNK, s32, M2C_UNK);      /* extern */
s32 BgCheck_GetBgCamSettingImpl(s32, s32, s32);                   /* extern */

s32 Camera_GetBgCamIndex(void *arg0, s32 *arg1, M2C_UNK arg2) {
    s32 sp1C;
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = SurfaceType_GetBgCamIndex(M2C_FIELD(arg0, s32 *, 0x8C) + 0x830, arg2, *arg1, arg2);
    sp1C = temp_v0;
    if (BgCheck_GetBgCamSettingImpl(M2C_FIELD(arg0, s32 *, 0x8C) + 0x830, temp_v0, *arg1) == 0) {
        var_v1 = -1;
    } else {
        var_v1 = sp1C;
    }
    return var_v1;
}

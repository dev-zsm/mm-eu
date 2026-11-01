// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 Camera_ChangeSettingFlags(void *, s16, M2C_UNK);            /* extern */

s32 Camera_ChangeSetting(void *arg0, s16 arg1) {
    s32 temp_v0;

    temp_v0 = Camera_ChangeSettingFlags(arg0, arg1, 0);
    if (temp_v0 >= 0) {
        M2C_FIELD(arg0, s16 *, 0x148) = -1;
    }
    return temp_v0;
}

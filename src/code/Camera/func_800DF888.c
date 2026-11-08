// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 Camera_ChangeSettingFlags(void *, s16, M2C_UNK);            /* extern */

s32 Camera_ChangeSetting(struct Camera *camera, s16 setting) {
    s32 temp_v0;

    temp_v0 = Camera_ChangeSettingFlags(camera, setting, 0);
    if (temp_v0 >= 0) {
        M2C_FIELD(camera, s16 *, 0x148) = -1;
    }
    return temp_v0;
}

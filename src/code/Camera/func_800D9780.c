// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 Camera_Normal1();                                /* extern */

s32 Camera_Unique3(void *arg0) {
    s32 temp_v0;

    temp_v0 = Camera_Normal1();
    if ((M2C_FIELD(M2C_FIELD(arg0, void **, 0x8C), s16 *, 0xA4) == 0x46) && (M2C_FIELD(arg0, f32 *, 0x60) < 5.0f)) {
        M2C_FIELD(arg0, f32 *, 0x60) = 5.0f;
    }
    return temp_v0;
}

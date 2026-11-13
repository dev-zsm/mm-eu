#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0506.h"

f32 func_800FFAD8(s32, f32, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK func_80B57160(u8 *, s32, M2C_UNK);        /* extern */

void func_800015E8(u8 *arg0, s32 arg1) {
    s32 temp_v0;

    if (func_800FFAD8(arg0 + 0xC4, 0, 0x3F000000, 0x43FA0000, 10.0f) != 0.0f) {
        func_80B57160(arg0, arg1, 1);
    }
    temp_v0 = M2C_FIELD(arg0, u8 *, 0xD0);
    if (temp_v0 != 0xFF) {
        if ((s32) temp_v0 >= 0xEB) {
            M2C_FIELD(arg0, u8 *, 0xD0) = 0xFFU;
            return;
        }
        M2C_FIELD(arg0, u8 *, 0xD0) = (u8) (temp_v0 + 0x14);
    }
}

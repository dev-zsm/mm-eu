// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_800FFAD8(u8 *, s32, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK func_80A0C6A0(u8 *, s32);                 /* extern */
M2C_UNK func_80A0D0A8(u8 *);                      /* extern */

void func_80000DA8(u8 *arg0, s32 arg1) {
    if (func_800FFAD8(arg0 + 0x28, M2C_FIELD(arg0, s32 *, 0x88), 0x3F333333, 0x41F00000, 10.0f) < 1.0f) {
        M2C_FIELD(arg0, s16 *, 0x29E) = (s16) (M2C_FIELD(arg0, s16 *, 0x29E) - 1);
        if (M2C_FIELD(arg0, s16 *, 0x29E) >= 0x10) {
            func_80A0C6A0(arg0, arg1);
        }
        if (M2C_FIELD(arg0, s16 *, 0x29E) == 0) {
            func_80A0D0A8(arg0);
        }
    } else {
        func_80A0C6A0(arg0, arg1);
    }
}

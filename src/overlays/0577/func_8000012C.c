// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5C34(s32, s8);                         /* extern */
s32 func_80BBB3D8(s16 *, u8 *, M2C_UNK);          /* extern */
M2C_UNK func_80BBB4F4(u8 *);                      /* extern */

void func_8000012C(u8 *arg0, s32 arg1) {
    s16 sp26;

    if (func_800B5C34(arg1, M2C_FIELD(arg0, s8 *, 3)) != 0) {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 9);
    }
    if ((func_80BBB3D8(&sp26, arg0 + 0x160, 1) == 0) && (sp26 < 0) && (func_800B5C34(arg1, M2C_FIELD(arg0, s8 *, 3)) != 0)) {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 1);
        if (M2C_FIELD(arg0, u8 *, 0x114) != 0) {
            func_80BBB4F4(arg0);
        }
    } else {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
    }
}

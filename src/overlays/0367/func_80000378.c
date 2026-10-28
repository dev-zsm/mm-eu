// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
s32 func_8013DA3C(s32, s16, u8 *, u8 *);        /* extern */

void func_80000378(u8 *arg0) {
    s32 temp_a0;

    if (M2C_FIELD(arg0, s16 *, 0x352) != -1) {
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x2AC);
        if ((temp_a0 != 0) && (func_8013DA3C(temp_a0, M2C_FIELD(arg0, s16 *, 0x2B0), arg0 + 0x408, arg0) == 0)) {
            func_800B6490(arg0);
        }
    }
}

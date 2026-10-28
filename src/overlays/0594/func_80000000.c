// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
s32 func_8013DA3C(s32, s16, u8 *, u8 *);        /* extern */

void func_80000000(u8 *arg0) {
    s32 temp_a0;

    if (M2C_FIELD(arg0, s16 *, 0x27A) != -1) {
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x258);
        if ((temp_a0 != 0) && (func_8013DA3C(temp_a0, M2C_FIELD(arg0, s16 *, 0x25C), arg0 + 0x268, arg0) == 0)) {
            func_800B6490(arg0);
        }
    }
}

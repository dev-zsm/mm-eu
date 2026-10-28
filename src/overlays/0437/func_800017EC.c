// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800F1EA8(s16);                             /* extern */
s32 func_8013E684(u8 *, s16, s16, M2C_UNK);       /* extern */
M2C_UNK func_80151E7C(s32, M2C_UNK);                /* extern */
M2C_UNK func_80AD29EC(u8 *, s32);                 /* extern */

void func_800017EC(u8 *arg0, s32 arg1) {
    s16 temp_a2;

    temp_a2 = M2C_FIELD(arg0, s16 *, 0x1C);
    if ((temp_a2 >= 0) && (func_8013E684(arg0, M2C_FIELD(arg0, s16 *, 0x314), temp_a2, 0) != 0)) {
        M2C_FIELD(arg0, s16 *, 0x2E8) = func_800F1EA8(M2C_FIELD(arg0, s16 *, 0x314));
        func_80151E7C(arg1, 0x1411);
        func_80AD29EC(arg0, arg1);
    }
}

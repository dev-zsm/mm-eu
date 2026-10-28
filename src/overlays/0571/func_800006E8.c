// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80137C58(u8 *, s32);                     /* extern */
M2C_UNK func_80BB78AC(u8 *, M2C_UNK);             /* extern */

void func_800006E8(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x2FE);
    if (temp_v0 == 0) {
        func_80BB78AC(arg0, 2);
        M2C_FIELD(arg0, s16 *, 0x2FE) = (s16) (M2C_FIELD(arg0, s16 *, 0x2FE) + 1);
        return;
    }
    if ((temp_v0 == 1) && (func_80137C58(arg0 + 0x144, M2C_FIELD(arg0, s32 *, 0x154)) != 0)) {
        func_80BB78AC(arg0, 3);
        M2C_FIELD(arg0, s16 *, 0x2FE) = (s16) (M2C_FIELD(arg0, s16 *, 0x2FE) + 1);
    }
}

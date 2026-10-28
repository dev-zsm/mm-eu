// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(s32, M2C_UNK);                /* extern */
s32 func_80137C58(s32, M2C_UNK);                    /* extern */

void func_80007A2C(s32 arg0) {
    s32 sp18;
    s32 temp_a0;

    temp_a0 = arg0 + 0x144;
    sp18 = temp_a0;
    if ((func_80137C58(temp_a0, 0x3F800000) != 0) || (func_80137C58(temp_a0, 0x40E00000) != 0)) {
        func_800B8C4C(arg0, 0x28EF);
    }
}

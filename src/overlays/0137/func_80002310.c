// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80904094();                            /* extern */
M2C_UNK func_80904320();                            /* extern */

void func_80002310(u8 *arg0) {
    s16 temp_v0;
    s8 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x242);
    if (temp_v0 > 0) {
        M2C_FIELD(arg0, s16 *, 0x242) = (s16) (temp_v0 - 1);
        func_80904320();
    } else {
        func_80904094();
    }
    temp_v0_2 = M2C_FIELD(arg0, s8 *, 0x276);
    if (temp_v0_2 > 0) {
        M2C_FIELD(arg0, s8 *, 0x276) = (s8) (temp_v0_2 - 1);
    }
}

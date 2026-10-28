// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80000E50(u8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x19C);
    if (temp_v0 > 0) {
        M2C_FIELD(arg0, s16 *, 0x19C) = (s16) (temp_v0 - 1);
    }
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x144)();
}

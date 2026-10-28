// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_800009E4(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x21E);
    if (temp_v0 >= 0x65) {
        M2C_FIELD(arg0, s8 *, 0xB7) = 0;
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x21E) = (s16) (temp_v0 + 1);
}

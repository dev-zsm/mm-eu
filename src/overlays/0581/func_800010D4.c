// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_800010D4(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x316);
    if (temp_v0 < 0x28) {
        M2C_FIELD(arg0, s16 *, 0x316) = (s16) (temp_v0 + 1);
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x312) = (s16) (M2C_FIELD(arg0, s16 *, 0x312) + 1);
    if (M2C_FIELD(arg0, s16 *, 0x312) >= 3) {
        M2C_FIELD(arg0, s16 *, 0x312) = 0;
        M2C_FIELD(arg0, s16 *, 0x316) = 0;
    }
}

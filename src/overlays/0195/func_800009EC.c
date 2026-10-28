// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, s16, s32); /* extern */

void func_800009EC(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    if ((M2C_FIELD(arg0, s16 *, 0x52E) == 0) && (M2C_FIELD(arg0, s16 *, 0x52A) == 0)) {
        func_800FFCBC(arg0 + 0x32, (s16) (M2C_FIELD(arg0, s16 *, 0x92) ^ 0x8000), 4, M2C_FIELD(arg0, s16 *, 0x51E), 1);
    }
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x52A);
    M2C_FIELD(arg0, s16 *, 0xBE) = (s16) M2C_FIELD(arg0, s16 *, 0x32);
    if (temp_v0 < 0x1E) {
        if (temp_v0 & 1) {
            M2C_FIELD(arg0, s16 *, 0xBE) = (s16) (M2C_FIELD(arg0, s16 *, 0xBE) + 0x7D0);
            return;
        }
        M2C_FIELD(arg0, s16 *, 0xBE) = (s16) (M2C_FIELD(arg0, s16 *, 0xBE) - 0x7D0);
    }
}

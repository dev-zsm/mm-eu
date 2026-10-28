// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_808AF7B8();                            /* extern */

void func_80000370(u8 *arg0, M2C_UNK arg1) {
    u8 temp_v0;

    if (((M2C_FIELD(arg0, u8 *, 0x2FA) & 2) && (M2C_FIELD(arg0, u8 *, 0x2FB) & 1)) || (M2C_FIELD(arg0, u8 *, 0x345) & 2)) {
        if (M2C_FIELD(arg0, u8 *, 0x234) == 0) {
            func_808AF7B8();
        }
    } else {
        temp_v0 = M2C_FIELD(arg0, u8 *, 0x234);
        if ((s32) temp_v0 >= 0xB) {
            M2C_FIELD(arg0, u8 *, 0x234) = (u8) (temp_v0 - 0xA);
            return;
        }
        M2C_FIELD(arg0, u8 *, 0x234) = 0U;
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
        M2C_FIELD(arg0, s16 *, 0x23A) = 0;
    }
}

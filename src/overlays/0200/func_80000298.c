// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FED2C(u8 *, M2C_UNK, s16, u8 *); /* extern */

void func_80000298(s32 arg0, M2C_UNK arg1, u8 *arg2) {
    s16 temp_v0;

    func_800FED2C(arg2 + 0x46, 0, M2C_FIELD(arg2, s16 *, 0x50), arg2);
    temp_v0 = M2C_FIELD(arg2, s16 *, 0x54);
    M2C_FIELD(arg2, s16 *, 0x52) = (s16) (M2C_FIELD(arg2, s16 *, 0x52) + temp_v0);
    if (temp_v0 != 0) {
        M2C_FIELD(arg2, s16 *, 0x54) = (s16) (temp_v0 - M2C_FIELD(arg2, s16 *, 0x56));
    }
}

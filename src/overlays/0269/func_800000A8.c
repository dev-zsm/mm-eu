// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

u8 *func_8013D9F8(M2C_UNK, s16, M2C_UNK);         /* extern */

void func_800000A8(u8 *arg0, M2C_UNK arg1) {
    s16 var_s1;
    s32 var_s0;
    u8 *temp_v0;

    var_s1 = 0;
    var_s0 = (s32) (M2C_FIELD(arg0, s16 *, 0x1C) & 0x7E00) >> 9;
    if (var_s0 != 0x3F) {
        do {
            temp_v0 = func_8013D9F8(arg1, (s16) var_s0, 0x3F);
            M2C_FIELD((arg0 + (var_s1 * 4)), u8 **, 0x1D8) = temp_v0;
            var_s0 = (s32) M2C_FIELD(temp_v0, u8 *, 1);
            var_s1 += 1;
        } while (var_s0 != 0xFF);
    }
}

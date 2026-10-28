// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_800FF7A4(u8 *, u8 *, s32, u8 *);     /* extern */
M2C_UNK func_80B6185C(u8 *);                      /* extern */

void func_80000A54(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    if (func_800FF7A4(arg0 + 0x24, arg0 + 0x2B0, M2C_FIELD(arg0, s32 *, 0x70), arg0) < 2.0f) {
        func_80B6185C(arg0);
    }
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x30A);
    if (temp_v0 == 0) {
        func_80B6185C(arg0);
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x30A) = (s16) (temp_v0 - 1);
}

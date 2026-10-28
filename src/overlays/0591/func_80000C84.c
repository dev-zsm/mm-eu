// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801342C8(s32, s32, s32, u8, s32, s32, u8 *); /* extern */
M2C_UNK func_80181D88(s16, M2C_UNK);                /* extern */

void func_80000C84(u8 *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, f32 *, 0x160) < 1400.0f) {
        func_80181D88(M2C_FIELD(arg0, s16 *, 0x15A), 1);
        func_801342C8(arg1, M2C_FIELD(arg0, s32 *, 0x168), M2C_FIELD(arg0, s32 *, 0x184), M2C_FIELD(arg0, u8 *, 0x166), 0, 0, arg0);
    }
}

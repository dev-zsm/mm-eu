// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800BA9E4(s32, s32, M2C_UNK, s32, f32, f32, s32, s32, s32, s32); /* extern */
s16 func_800FF894(u8 *, s32);                     /* extern */
M2C_UNK func_80115FD8(s32, M2C_UNK, M2C_UNK);       /* extern */
extern s8 D_801E6F29;

void func_80005810(s32 arg0, u8 *arg1, s32 arg2, s32 arg3) {
    s16 var_v1;
    s32 temp_v0;

    if (arg2 != 0) {
        M2C_FIELD(arg1, f32 *, 0xB08) = 0.0f;
    } else {
        M2C_FIELD(arg1, f32 *, 0xB08) = 0.5f;
    }
    M2C_FIELD(arg1, s32 *, 0xA6C) = (s32) (M2C_FIELD(arg1, s32 *, 0xA6C) | 0x1000);
    if ((M2C_FIELD(arg1, s16 *, 0) == 0) && ((arg3 != 0) || (M2C_FIELD(arg1, u8 *, 0x14B) == 4))) {
        var_v1 = 0;
        if (arg3 != 0) {
            temp_v0 = M2C_FIELD(arg1, s32 *, 0x730);
            if (temp_v0 != 0) {
                var_v1 = func_800FF894(arg1 + 0xBEC, temp_v0 + 0x3C);
            }
            if (D_801E6F29 != 0) {
                goto block_10;
            }
        } else {
block_10:
            if ((func_800BA9E4(arg0 + 0x1CA0, arg0, 0x35, M2C_FIELD(arg1, s32 *, 0xBEC), M2C_FIELD(arg1, f32 *, 0xBF0), M2C_FIELD(arg1, f32 *, 0xBF4), (s32) var_v1, 0, 0, (M2C_FIELD(arg1, s8 *, 0x147) - 3) | arg2) != 0) && (arg3 != 0)) {
                func_80115FD8(arg0, 1, 7);
                M2C_FIELD(arg1, s8 *, 0xD57) = 4;
            }
        }
    }
}

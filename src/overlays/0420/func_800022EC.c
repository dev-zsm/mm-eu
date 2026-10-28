// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8018132C(f32, f32, s32, M2C_UNK);      /* extern */
M2C_UNK func_8018142C(f32, f32, s32, M2C_UNK);      /* extern */
M2C_UNK func_80181508(s16, M2C_UNK);                /* extern */
M2C_UNK func_80181A3C(s16, M2C_UNK);                /* extern */
M2C_UNK func_80181D88(s16, M2C_UNK);                /* extern */

void func_800022EC(s32 arg0, s32 arg1, u8 *arg2) {
    if (arg1 == 0x15) {
        func_8018132C(M2C_FIELD(arg2, f32 *, 0x3C8), M2C_FIELD(arg2, f32 *, 0x3CC), M2C_FIELD(arg2, s32 *, 0x3D0), 0);
        func_8018142C(M2C_FIELD(arg2, f32 *, 0x58), M2C_FIELD(arg2, f32 *, 0x5C), M2C_FIELD(arg2, s32 *, 0x60), 1);
        func_80181A3C(M2C_FIELD(arg2, s16 *, 0x3C4), 1);
        func_80181508(M2C_FIELD(arg2, s16 *, 0x3C2), 1);
        func_80181D88(M2C_FIELD(arg2, s16 *, 0x3C6), 1);
    }
}

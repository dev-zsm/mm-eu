// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8018132C(f32, f32, s32, M2C_UNK);      /* extern */
M2C_UNK func_8018142C(f32, f32, s32, M2C_UNK);      /* extern */
M2C_UNK func_80181508(s16, M2C_UNK);                /* extern */
M2C_UNK func_80181A3C(s16, M2C_UNK);                /* extern */
M2C_UNK func_80181D88(s16, M2C_UNK);                /* extern */
M2C_UNK func_80A74680(s16, s16, u8 *, u8 *, s32); /* extern */

void func_80004444(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, u8 *arg4) {
    s32 var_v0;

    var_v0 = 0;
    if (M2C_FIELD(arg4, u16 *, 0x42C) & 1) {
        var_v0 = 1;
    }
    if (arg1 == 0x15) {
        func_80A74680(M2C_FIELD(arg4, s16 *, 0x428), M2C_FIELD(arg4, s16 *, 0x42A), arg4 + 0x41C, arg4 + 0x416, var_v0);
        func_8018132C(M2C_FIELD(arg4, f32 *, 0x41C), M2C_FIELD(arg4, f32 *, 0x420), M2C_FIELD(arg4, s32 *, 0x424), 0);
        func_8018142C(M2C_FIELD(arg4, f32 *, 0x58), M2C_FIELD(arg4, f32 *, 0x5C), M2C_FIELD(arg4, s32 *, 0x60), 1);
        func_80181A3C(M2C_FIELD(arg4, s16 *, 0x418), 1);
        func_80181508(M2C_FIELD(arg4, s16 *, 0x416), 1);
        func_80181D88(M2C_FIELD(arg4, s16 *, 0x41A), 1);
    }
}

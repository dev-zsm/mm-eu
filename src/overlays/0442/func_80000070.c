// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FED2C(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_801017FC(u8 *, s16, s16, s16, s32, s32, s32, s32); /* extern */

void func_80000070(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, f32 *, 0x98) < M2C_FIELD(arg0, f32 *, 0x1A8)) {
        func_800FED2C(arg0 + 0x1A6, 0x96, 0x32);
    } else {
        func_800FED2C(arg0 + 0x1A6, 0, 0x32);
    }
    func_801017FC(arg0 + 0x1B0, (s16) (s32) M2C_FIELD(arg0, f32 *, 0x24), (s16) (s32) (M2C_FIELD(arg0, f32 *, 0x28) + 100.0f), (s16) (s32) M2C_FIELD(arg0, f32 *, 0x2C), 0xFF, 0xFF, 0xFF, (s32) M2C_FIELD(arg0, s16 *, 0x1A6));
}

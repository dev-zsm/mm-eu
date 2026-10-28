// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801017FC(u8 *, s16, s16, s16, s32, s32, u32, s32); /* extern */

void func_800011FC(u8 *arg0) {
    f32 temp_f0;
    s32 temp_v0;

    M2C_FIELD(arg0, M2C_UNK (**)(u8 *), 0x1B8)(arg0);
    temp_f0 = M2C_FIELD(arg0, f32 *, 0x1A4);
    temp_v0 = (u32) (temp_f0 * 255.0f) & 0xFF;
    func_801017FC(arg0 + 0x194, (s16) (s32) M2C_FIELD(arg0, f32 *, 0x24), (s16) (s32) M2C_FIELD(arg0, f32 *, 0x28), (s16) (s32) M2C_FIELD(arg0, f32 *, 0x2C), temp_v0, temp_v0, (u32) (temp_f0 * 100.0f), (s32) (temp_f0 * 800.0f));
}

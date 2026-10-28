// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BE404(s32 *, u8 *, u8 *, s16, f32, f32, f32, s32); /* extern */
M2C_UNK func_8012C73C(s32);                         /* extern */
M2C_UNK func_80133EDC(s32 *, s32, s32, M2C_UNK *, M2C_UNK *, u8 *); /* extern */
extern M2C_UNK D_80B57BB8;
extern M2C_UNK D_80B57D5C;

void func_8000292C(u8 *arg0, s32 *arg1) {
    u8 temp_v0;

    M2C_FIELD(arg0, s32 *, 0x2DC) = 0;
    func_8012C73C(*arg1);
    func_80133EDC(arg1, M2C_FIELD(arg0, s32 *, 0x1E8), M2C_FIELD(arg0, s32 *, 0x204), &D_80B57BB8, &D_80B57D5C, arg0);
    if (M2C_FIELD(arg0, s16 *, 0x3F0) > 0) {
        func_800BE404(arg1, arg0, arg0 + 0x234, M2C_FIELD(arg0, s16 *, 0x2DE), M2C_FIELD(arg0, f32 *, 0x2F0), 0.5f, M2C_FIELD(arg0, f32 *, 0x2EC), (s32) M2C_FIELD(arg0, u8 *, 0x403));
    }
    temp_v0 = M2C_FIELD(arg0, u8 *, 0x402);
    if ((temp_v0 & 0x40) && !(temp_v0 & 0x80)) {
        M2C_FIELD(arg0, u8 *, 0x402) = (u8) (temp_v0 | 0x80);
    }
}

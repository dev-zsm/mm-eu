// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BE404(s32 *, u8 *, u8 *, s16, f32, f32, f32, s32); /* extern */
M2C_UNK func_8012C73C(s32);                         /* extern */
M2C_UNK func_80133EDC(s32 *, s32, s32, M2C_UNK *, M2C_UNK *, u8 *); /* extern */
extern M2C_UNK D_80C065F8;
extern M2C_UNK D_80C06774;

void func_80001EAC(u8 *arg0, s32 *arg1) {
    u8 temp_v0;

    M2C_FIELD(arg0, s32 *, 0x2DC) = 0;
    func_8012C73C(*arg1);
    func_80133EDC(arg1, M2C_FIELD(arg0, s32 *, 0x1E8), M2C_FIELD(arg0, s32 *, 0x204), &D_80C065F8, &D_80C06774, arg0);
    if (M2C_FIELD(arg0, s16 *, 0x3E2) > 0) {
        func_800BE404(arg1, arg0, arg0 + 0x22C, M2C_FIELD(arg0, s16 *, 0x2DE), M2C_FIELD(arg0, f32 *, 0x2D8), 0.5f, M2C_FIELD(arg0, f32 *, 0x2D4), (s32) M2C_FIELD(arg0, u8 *, 0x3E9));
    }
    temp_v0 = M2C_FIELD(arg0, u8 *, 0x3E8);
    if (temp_v0 & 4) {
        M2C_FIELD(arg0, u8 *, 0x3E8) = (u8) (temp_v0 | 8);
    }
}

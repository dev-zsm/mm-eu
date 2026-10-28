// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BE404(s32 *, u8 *, u8 *, s16, f32, f32, f32, s32); /* extern */
M2C_UNK func_8012C73C(s32);                         /* extern */
M2C_UNK func_80133EDC(s32 *, s32, s32, M2C_UNK *, M2C_UNK *, u8 *); /* extern */
extern M2C_UNK D_8097BCB8;
extern M2C_UNK D_8097BE10;

void func_80002AC8(u8 *arg0, s32 *arg1) {
    s16 temp_v0;

    M2C_FIELD(arg0, s32 *, 0x2DC) = 0;
    func_8012C73C(*arg1);
    func_80133EDC(arg1, M2C_FIELD(arg0, s32 *, 0x148), M2C_FIELD(arg0, s32 *, 0x164), &D_8097BCB8, &D_8097BE10, arg0);
    if (M2C_FIELD(arg0, s16 *, 0x3D2) > 0) {
        func_800BE404(arg1, arg0, arg0 + 0x234, M2C_FIELD(arg0, s16 *, 0x2DE), M2C_FIELD(arg0, f32 *, 0x230), 0.5f, M2C_FIELD(arg0, f32 *, 0x22C), (s32) M2C_FIELD(arg0, u8 *, 0x3E6));
    }
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x3D8);
    if (temp_v0 & 0x40) {
        M2C_FIELD(arg0, s16 *, 0x3D8) = (s16) (temp_v0 | 0x80);
    }
}

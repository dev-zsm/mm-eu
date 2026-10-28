// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BE404(s32 *, u8 *, u8 *, M2C_UNK, f32, f32, f32, s32); /* extern */
M2C_UNK func_8012C73C(s32);                         /* extern */
M2C_UNK func_801342C8(s32 *, s32, s32, u8, s32, M2C_UNK *, u8 *); /* extern */
M2C_UNK func_80181A3C(s16, M2C_UNK);                /* extern */
extern M2C_UNK D_8086CE50;

void func_80003B08(u8 *arg0, s32 *arg1) {
    func_8012C73C(*arg1);
    func_80181A3C(M2C_FIELD(arg0, s16 *, 0x2B8), 1);
    func_801342C8(arg1, M2C_FIELD(arg0, s32 *, 0x148), M2C_FIELD(arg0, s32 *, 0x164), M2C_FIELD(arg0, u8 *, 0x146), 0, &D_8086CE50, arg0);
    func_800BE404(arg1, arg0, arg0 + 0x2F4, 0xC, M2C_FIELD(arg0, f32 *, 0x2C8), M2C_FIELD(arg0, f32 *, 0x2CC), M2C_FIELD(arg0, f32 *, 0x2C4), (s32) M2C_FIELD(arg0, u8 *, 0x2AC));
}

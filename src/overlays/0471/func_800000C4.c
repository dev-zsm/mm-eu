// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B763C(s32, u8 *, M2C_UNK, M2C_UNK, f32, s32); /* extern */
M2C_UNK func_800E26E8(s32, s32, u8 *, s32);       /* extern */

void func_800000C4(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s16 *, 0x1D6) = (s16) (s32) M2C_FIELD(arg0, f32 *, 0x24);
    M2C_FIELD(arg0, s16 *, 0x1D8) = (s16) (s32) M2C_FIELD(arg0, f32 *, 0x28);
    M2C_FIELD(arg0, s16 *, 0x1DA) = (s16) (s32) M2C_FIELD(arg0, f32 *, 0x2C);
    func_800E26E8(arg1, arg1 + 0x18884, arg0 + 0x190, arg1);
    func_800B763C(arg1, arg0, 0x41D00000, 0x41200000, 0.0f, 5);
}

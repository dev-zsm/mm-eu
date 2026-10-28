// FLAGS: -O1 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B2414(s32, f32 *, M2C_UNK, M2C_UNK, s32); /* extern */

void func_80000540(u8 *arg0, s32 arg1) {
    f32 sp2C;
    f32 sp28;
    f32 sp24;

    sp24 = M2C_FIELD(arg0, f32 *, 0x24);
    sp28 = M2C_FIELD(arg0, f32 *, 0xC);
    sp2C = M2C_FIELD(arg0, f32 *, 0x2C);
    func_800B2414(arg1, &sp24, 0x3E8, 0x578, 0);
}

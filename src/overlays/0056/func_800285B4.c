// FLAGS: -O1 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800C4D14(s32, M2C_UNK *, f32 *, M2C_UNK, M2C_UNK *, M2C_UNK *, u8 *); /* extern */

void func_800285B4(s32 arg0, u8 *arg1) {
    M2C_UNK sp3C;
    M2C_UNK sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    M2C_UNK sp28;

    sp2C = M2C_FIELD(arg1, f32 *, 0x24);
    sp30 = M2C_FIELD(arg1, f32 *, 0x28) - 20.0f;
    sp34 = M2C_FIELD(arg1, f32 *, 0x2C);
    func_800C4D14(arg0 + 0x830, &sp28, &sp2C, 0x41F00000, &sp3C, &sp38, arg1);
}

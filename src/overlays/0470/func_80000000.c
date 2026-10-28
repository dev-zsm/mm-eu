// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800C9F3C(s32, s32, s32, s32, f32 *, M2C_UNK *); /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_80B091B0;

void func_80000000(u8 *arg0, s32 arg1) {
    s32 pad[2];
    M2C_UNK sp2C;
    f32 sp28;

    func_800FF8DC(arg0, &D_80B091B0);
    if ((func_800C9F3C(arg1, arg1 + 0x830, M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x2C), &sp28, &sp2C) != 0) && (M2C_FIELD(arg0, f32 *, 0x28) < sp28)) {
        M2C_FIELD(arg0, s8 *, 0x144) = 1;
    }
}

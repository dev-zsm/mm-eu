// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800C9F3C(s32, s32, s32, s32, M2C_UNK *, u8 **); /* extern */
M2C_UNK func_800FF34C(u8 *, u8 *);              /* extern */

void func_80000288(u8 *arg0, s32 arg1) {
    u8 *sp2C;
    M2C_UNK sp28;

    if (func_800C9F3C(arg1, arg1 + 0x830, M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x2C), &sp28, &sp2C) != 0) {
        func_800FF34C(arg0 + 0x168, sp2C);
        M2C_FIELD(arg0, f32 *, 0x174) = (f32) M2C_FIELD(sp2C, s16 *, 6);
        M2C_FIELD(arg0, f32 *, 0x178) = (f32) M2C_FIELD(sp2C, s16 *, 8);
    }
}

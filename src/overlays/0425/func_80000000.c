// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
s32 func_800C5F18(s32, s32, u8 *, s32);           /* extern */
M2C_UNK func_800C92F4(M2C_UNK *, s32 *);            /* extern */
M2C_UNK func_800CABA0(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_60037F8;

void func_80000000(u8 *arg0, s32 arg1) {
    s32 pad[2];
    s32 sp24;

    sp24 = 0;
    func_800B6564(arg0, 0x3F800000);
    func_800CABA0(arg0, 1);
    func_800C92F4(&D_60037F8, &sp24);
    M2C_FIELD(arg0, s32 *, 0x144) = func_800C5F18(arg1, arg1 + 0x880, arg0, sp24);
    M2C_FIELD(arg0, s16 *, 0x160) = 0;
    M2C_FIELD(arg0, f32 *, 0x28) = (f32) (M2C_FIELD(arg0, f32 *, 0xC) + -10.0f);
}

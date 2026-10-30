// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
s32 func_800C5F18(s32, s32, u8 *, s32);           /* extern */
M2C_UNK func_800C92F4(M2C_UNK *, s32 *);            /* extern */
M2C_UNK func_800CABA0(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_60037F8;

void func_80000000(Actor *thisx, PlayState *play) {
    s32 pad[2];
    s32 sp24;

    sp24 = 0;
    func_800B6564(thisx, 0x3F800000);
    func_800CABA0(thisx, 1);
    func_800C92F4(&D_60037F8, &sp24);
    M2C_FIELD(thisx, s32 *, 0x144) = func_800C5F18(play, (u8 *)play + 0x880, thisx, sp24);
    M2C_FIELD(thisx, s16 *, 0x160) = 0;
    M2C_FIELD(thisx, f32 *, 0x28) = (f32) (M2C_FIELD(thisx, f32 *, 0xC) + -10.0f);
}

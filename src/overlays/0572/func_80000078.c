// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
s32 func_800C5F18(s32, s32, u8 *, s32);           /* extern */
M2C_UNK func_800C92F4(M2C_UNK *, s32 *);            /* extern */
M2C_UNK func_800CABA0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80BB8F88(u8 *);                      /* extern */
extern M2C_UNK D_60018C0;
extern M2C_UNK D_6001D10;

void func_80000078(Actor *thisx, PlayState *play) {
    s32 pad[2];
    s32 sp24;

    sp24 = 0;
    func_800B6564(thisx, 0x3DCCCCCD);
    func_800CABA0(thisx, 1);
    if (M2C_FIELD(thisx, s16 *, 0x1C) & 0x8000) {
        func_800C92F4(&D_6001D10, &sp24);
    } else {
        func_800C92F4(&D_60018C0, &sp24);
    }
    M2C_FIELD(thisx, s32 *, 0x144) = func_800C5F18(play, (u8 *)play + 0x880, thisx, sp24);
    M2C_FIELD(thisx, s16 *, 0x162) = 0;
    M2C_FIELD(thisx, s16 *, 0x164) = 0;
    M2C_FIELD(thisx, s16 *, 0x160) = (s16) M2C_FIELD(thisx, s8 *, 0x38);
    func_80BB8F88(thisx);
}

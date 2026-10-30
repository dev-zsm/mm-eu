// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

s32 func_800B5B20(s32, s32);                        /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
s32 func_800C5F18(s32, s32, u8 *, s32);           /* extern */
M2C_UNK func_800C92F4(M2C_UNK *, s32 *);            /* extern */
M2C_UNK func_800CABA0(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_600BF40;
extern M2C_UNK D_80AA265C;

void func_80000000(Actor *thisx, PlayState *play) {
    s32 pad;
    s32 sp28;
    s32 temp_a1;

    sp28 = 0;
    func_800B6564(thisx, 0x3DCCCCCD);
    M2C_FIELD(thisx, M2C_UNK **, 0x164) = &D_80AA265C;
    func_800CABA0(thisx, 0);
    func_800C92F4(&D_600BF40, &sp28);
    M2C_FIELD(thisx, s32 *, 0x144) = func_800C5F18(play, (u8 *)play + 0x880, thisx, sp28);
    temp_a1 = M2C_FIELD(thisx, s16 *, 0x1C) & 0x7F;
    M2C_FIELD(thisx, s16 *, 0x15C) = 0;
    M2C_FIELD(thisx, s16 *, 0x160) = 0;
    if ((temp_a1 != 0x7F) && (func_800B5B20(play, temp_a1) != 0)) {
        M2C_FIELD(thisx, s16 *, 0x15E) = 0x64;
        return;
    }
    M2C_FIELD(thisx, s16 *, 0x15E) = -1;
    M2C_FIELD(thisx, f32 *, 0x28) = (f32) (M2C_FIELD(thisx, f32 *, 0xC) - 320.0f);
}

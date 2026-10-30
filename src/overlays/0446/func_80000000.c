// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800E1134(s32, u8 *, u8 *, M2C_UNK *); /* extern */
extern M2C_UNK D_80ADC420;
extern M2C_UNK D_80ADC7C0;

void func_80000000(Actor *thisx, PlayState *play) {
    M2C_FIELD(thisx, s16 *, 0x18) = 0;
    M2C_FIELD(thisx, s16 *, 0x16) = 0;
    M2C_FIELD(thisx, s16 *, 0x190) = 0;
    M2C_FIELD(thisx, f32 *, 0xFC) = 4000.0f;
    M2C_FIELD(thisx, f32 *, 0x100) = 2000.0f;
    M2C_FIELD(thisx, f32 *, 0x104) = 2400.0f;
    func_800E1134(play, (u8 *)thisx + 0x144, thisx, &D_80ADC7C0);
    func_800B6564(thisx, 0x3F800000);
    M2C_FIELD(thisx, M2C_UNK **, 0x194) = &D_80ADC420;
}

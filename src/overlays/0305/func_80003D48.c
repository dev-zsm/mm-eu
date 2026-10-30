// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_80131AF8(s32, s32);                    /* extern */
M2C_UNK func_80A097D8(u8 *, s32);                 /* extern */
extern s32 D_80A0BBAC;

void func_80003D48(Actor *thisx, PlayState *play) {
    func_80131AF8(play, D_80A0BBAC);
    M2C_FIELD(thisx, M2C_UNK (**)(u8 *, s32), 0x1AC)(thisx, play);
    func_80A097D8(thisx, play);
}

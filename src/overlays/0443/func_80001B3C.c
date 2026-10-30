// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800E2318(s32, s32, u8 *);            /* extern */
M2C_UNK func_800E2500(s32, s32, u8 *);            /* extern */
M2C_UNK func_800E26E8(s32, s32, u8 *);            /* extern */
M2C_UNK func_80ADAB6C(u8 *, s32);                 /* extern */

void func_80001B3C(Actor *thisx, PlayState *play) {
    func_80ADAB6C(thisx, play);
    M2C_FIELD(thisx, M2C_UNK (**)(u8 *, s32), 0x1E8)(thisx, play);
    if (M2C_FIELD(thisx, u8 *, 0x284) & 1) {
        func_800E2318(play, (u8 *)play + 0x18884, (u8 *)thisx + 0x274);
    }
    if (M2C_FIELD(thisx, u8 *, 0x285) & 1) {
        func_800E2500(play, (u8 *)play + 0x18884, (u8 *)thisx + 0x274);
    }
    if (M2C_FIELD(thisx, u8 *, 0x286) & 1) {
        func_800E26E8(play, (u8 *)play + 0x18884, (u8 *)thisx + 0x274);
    }
}

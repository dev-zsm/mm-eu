// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800C625C(s32, s32, s32, s32);          /* extern */
M2C_UNK func_800E0FAC(s32, u8 *);                 /* extern */

void func_80000110(Actor *thisx, PlayState *play) {
    func_800C625C(play, (u8 *)play + 0x880, M2C_FIELD(thisx, s32 *, 0x144), play);
    func_800E0FAC(play, (u8 *)thisx + 0x1A0);
}

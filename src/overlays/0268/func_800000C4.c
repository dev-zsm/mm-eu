// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800C625C(s32, s32, s32, u8 *);       /* extern */

void func_800000C4(Actor *thisx, PlayState *play) {
    if (M2C_FIELD(thisx, s32 *, 0x13C) != 0) {
        func_800C625C(play, (u8 *)play + 0x880, M2C_FIELD(thisx, s32 *, 0x144), thisx);
    }
}

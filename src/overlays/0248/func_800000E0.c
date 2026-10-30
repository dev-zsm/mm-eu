// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B5BA4(s32, s32);                    /* extern */
s32 func_80984780(u8 *, s32);                     /* extern */

void func_800000E0(Actor *thisx, PlayState *play) {
    if (func_80984780(thisx, play) != 0) {
        func_800B5BA4(play, M2C_FIELD(thisx, s16 *, 0x1C) & 0x7F);
    }
}

// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B89D4(s32, s32);                    /* extern */
s32 func_80B08B00(s32, s32);                        /* extern */

void func_800000F0(Actor *thisx, PlayState *play) {
    if (func_80B08B00(thisx, play) == 0) {
        func_800B89D4(thisx, play);
    }
}

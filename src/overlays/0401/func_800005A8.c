// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

s32 func_8016A23C(s32);                             /* extern */

void func_800005A8(Actor *thisx, PlayState *play) {
    if (func_8016A23C(play) == 0) {
        M2C_FIELD(thisx, M2C_UNK (**)(u8 *, s32), 0x15C)(thisx, play);
    }
}

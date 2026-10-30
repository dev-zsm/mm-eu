// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800E09D8(M2C_UNK, s32, M2C_UNK, s32);  /* extern */

void func_8000141C(Actor *thisx, PlayState *play) {
    func_800E09D8(play, (u8 *)thisx + 0x144, play, thisx);
}

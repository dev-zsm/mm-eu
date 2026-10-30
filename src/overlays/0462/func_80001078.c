// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800BDD44(M2C_UNK, s32, u8 *, M2C_UNK); /* extern */

void func_80001078(Actor *thisx, PlayState *play) {
    func_800BDD44(play, M2C_FIELD(thisx, s32 *, 0x1A8), thisx, play);
}

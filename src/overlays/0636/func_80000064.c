// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

extern s32 D_801E6F00;

void func_80000064(Actor *thisx, PlayState *play) {
    M2C_FIELD(thisx, s8 *, 0x144) = (s8) D_801E6F00;
}

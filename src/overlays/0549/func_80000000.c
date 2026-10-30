// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

void func_80000000(Actor *thisx, PlayState *play) {
    M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) & ~1);
    if (!(M2C_FIELD(thisx, s16 *, 0x1C) & 0x100)) {
        M2C_FIELD(thisx, s8 *, 0x144) = 0;
        return;
    }
    M2C_FIELD(thisx, s16 *, 0x1C) = 0xC8;
    M2C_FIELD(thisx, s8 *, 0x144) = 1;
}

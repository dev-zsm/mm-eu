// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

extern M2C_UNK D_801E6EF0;

void func_80000054(Actor *thisx, PlayState *play) {
    if ((M2C_FIELD(thisx, s16 *, 0x1C) != 0x1FF) && ((s32) M2C_FIELD(&D_801E6EF0, u8 *, 0x3DD4) > 0)) {
        M2C_FIELD(&D_801E6EF0, u8 *, 0x3DD4) = 5U;
    }
}

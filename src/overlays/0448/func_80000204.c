// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

extern M2C_UNK D_801E6EF0;

void func_80000204(Actor *thisx, PlayState *play) {
    if ((M2C_FIELD(thisx, s16 *, 0x1C) & 0xF) != 1) {
        M2C_FIELD(&D_801E6EF0, u8 *, 0x100F) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0x100F) & 0xFD);
    }
}

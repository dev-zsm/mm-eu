// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

extern M2C_UNK D_801E6EF0;

void func_8000023C(Actor *thisx, PlayState *play) {
    M2C_FIELD(&D_801E6EF0, u8 *, 0xF37) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF37) & 0xFE);
}

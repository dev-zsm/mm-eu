// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

extern M2C_UNK D_801E6EF0;

void func_80000DE8(Actor *thisx, PlayState *play) {
    if (M2C_FIELD(&D_801E6EF0, u8 *, 0x3DD4) != 6) {
        M2C_FIELD(&D_801E6EF0, u8 *, 0x3DD4) = 5U;
    }
}

// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

extern M2C_UNK D_80991AF8;

void func_80000000(Actor *thisx, PlayState *play) {
    M2C_FIELD(thisx, M2C_UNK **, 0x144) = &D_80991AF8;
}

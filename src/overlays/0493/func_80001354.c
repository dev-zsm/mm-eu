// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0493.h"

extern M2C_UNK D_80B4137C;

void func_80001354(Actor *thisx, PlayState *play) {
    M2C_FIELD(thisx, M2C_UNK **, 0x144) = &D_80B4137C;
}

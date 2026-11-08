// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0160.h"

extern M2C_UNK D_809286CC;

void func_80000710(Actor *thisx) {
    M2C_FIELD(thisx, s16 *, 0x28A) = 1;
    M2C_FIELD(thisx, M2C_UNK **, 0x254) = &D_809286CC;
}

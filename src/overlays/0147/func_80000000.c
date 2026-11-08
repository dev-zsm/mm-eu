// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0147.h"

void func_80000000(Actor *thisx, s32 arg1) {
    M2C_FIELD(thisx, s32 *, 0x144) = arg1;
}

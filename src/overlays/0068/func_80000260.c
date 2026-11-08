// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0068.h"

void func_80000260(Actor *thisx) {
    if (M2C_FIELD(thisx, s16 *, 0x1C) == 0) {
        M2C_FIELD(thisx, s8 *, 0x18D) = 0;
        M2C_FIELD(thisx, s8 *, 0x338) = 1;
        M2C_FIELD(thisx, s8 *, 0x18C) = 1;
        M2C_FIELD(thisx, s8 *, 0x11F) = 0x11;
    }
}

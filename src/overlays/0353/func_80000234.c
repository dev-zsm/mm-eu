// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0353.h"

void func_80000234(Actor *thisx) {
    M2C_FIELD(M2C_FIELD(thisx, u8 **, 0x1AC), s8 *, 0x3C) = 0x16;
    M2C_FIELD(M2C_FIELD(thisx, u8 **, 0x1AC), s16 *, 0x2E) = 0x19;
    M2C_FIELD(M2C_FIELD(thisx, u8 **, 0x1AC), s16 *, 0x28) = 0;
}

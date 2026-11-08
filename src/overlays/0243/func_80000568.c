// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0243.h"

extern M2C_UNK D_8097FE0C;

void func_80000568(Actor *thisx) {
    M2C_FIELD(thisx, s16 *, 0x18E) = 0x12C;
    M2C_FIELD(thisx, M2C_UNK **, 0x188) = &D_8097FE0C;
    M2C_FIELD(thisx, f32 *, 0x70) = 4.0f;
    M2C_FIELD(thisx, f32 *, 0x160) = 2.0f;
}

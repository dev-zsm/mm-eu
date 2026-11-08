// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0068.h"

extern M2C_UNK D_80879C68;

void func_80000E1C(Actor *thisx) {
    M2C_FIELD(thisx, s16 *, 0x30) = 0x7000;
    M2C_FIELD(thisx, s16 *, 0x190) = 0x12;
    M2C_FIELD(thisx, M2C_UNK **, 0x188) = &D_80879C68;
    M2C_FIELD(thisx, f32 *, 0x160) = 1.0f;
    M2C_FIELD(thisx, f32 *, 0x70) = 2.5f;
}

// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0151.h"

extern M2C_UNK D_809182C4;

void func_80001300(Actor *thisx) {
    M2C_FIELD(thisx, s8 *, 0xBD6) = 3;
    M2C_FIELD(thisx, s8 *, 0xBCE) = 0;
    M2C_FIELD(thisx, s8 *, 0xBD8) = 1;
    M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) & ~1);
    M2C_FIELD(thisx, f32 *, 0x70) = 0.0f;
    M2C_FIELD(thisx, f32 *, 0xBBC) = 0.0f;
    M2C_FIELD(thisx, M2C_UNK **, 0x144) = &D_809182C4;
}

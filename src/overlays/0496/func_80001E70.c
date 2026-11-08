// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0496.h"

extern M2C_UNK D_80B481A4;

void func_80001E70(Actor *thisx) {
    M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) & ~1);
    M2C_FIELD(thisx, M2C_UNK **, 0x200) = &D_80B481A4;
}

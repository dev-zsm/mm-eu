// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0306.h"

extern M2C_UNK D_80A0CF0C;

void func_80000C94(Actor *thisx) {
    M2C_FIELD(thisx, s32 *, 0x13C) = 0;
    M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) & ~1);
    M2C_FIELD(thisx, M2C_UNK **, 0x298) = &D_80A0CF0C;
}

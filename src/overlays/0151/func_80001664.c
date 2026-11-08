// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0151.h"

extern M2C_UNK D_80918628;

void func_80001664(Actor *thisx) {
    M2C_FIELD(thisx, s8 *, 0xBD6) = 1;
    M2C_FIELD(thisx, s16 *, 0xBCA) = 0x28;
    M2C_FIELD(thisx, s8 *, 0xBCC) = 1;
    M2C_FIELD(thisx, s8 *, 0xBCE) = 1;
    M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) | 1);
    M2C_FIELD(thisx, M2C_UNK **, 0x144) = &D_80918628;
    M2C_FIELD(thisx, f32 *, 0x74) = -1.0f;
}

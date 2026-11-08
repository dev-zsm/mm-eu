// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0148.h"

extern M2C_UNK D_80914368;

void EnHonotrap_SetupFlameGroup(EnHonotrap *this) {
    M2C_FIELD(this, M2C_UNK **, 0x144) = &D_80914368;
    M2C_FIELD(this, s16 *, 0x220) = 0x50;
    M2C_FIELD(this, f32 *, 0x244) = 0.0f;
}

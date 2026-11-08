// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0148.h"

extern M2C_UNK D_809138C8;

void EnHonotrap_SetupEyeAttack(EnHonotrap *this) {
    M2C_FIELD(this, M2C_UNK **, 0x144) = &D_809138C8;
    M2C_FIELD(this, s16 *, 0x222) = 0;
}

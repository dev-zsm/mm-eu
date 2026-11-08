// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0513.h"

extern M2C_UNK D_80B647BC;

void BgIkanaMirror_SetupWait(BgIkanaMirror *this) {
    M2C_FIELD(this, s8 *, 0x5C8) = 0;
    M2C_FIELD(this, M2C_UNK **, 0x5B8) = &D_80B647BC;
}

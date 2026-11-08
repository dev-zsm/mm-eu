// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0504.h"

extern M2C_UNK D_80B54204;

void BgKin2Picture_SetupWait(BgKin2Picture *this) {
    M2C_FIELD(this, M2C_UNK **, 0x234) = &D_80B54204;
}

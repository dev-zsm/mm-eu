// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0593.h"

extern M2C_UNK D_80BCAE70;

void EnTanron6_DoNothing(EnTanron6 *this) {
    M2C_FIELD(this, M2C_UNK **, 0x200) = &D_80BCAE70;
}

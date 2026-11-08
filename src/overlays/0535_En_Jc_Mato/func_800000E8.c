// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0535.h"

extern M2C_UNK D_80B82D7C;

void EnJcMato_SetupIdle(EnJcMato *this) {
    M2C_FIELD(this, M2C_UNK **, 0x144) = &D_80B82D7C;
}

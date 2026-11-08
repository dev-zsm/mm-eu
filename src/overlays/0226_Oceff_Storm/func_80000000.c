// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0226.h"

void OceffStorm_SetupAction(OceffStorm *this, s32 arg1) {
    M2C_FIELD(this, s32 *, 0x14C) = arg1;
}

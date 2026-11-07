// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0148.h"

extern M2C_UNK D_80913BFC;

void EnHonotrap_SetupFlameGrow(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80913BFC;
}

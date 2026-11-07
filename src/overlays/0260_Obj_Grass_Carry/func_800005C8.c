// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0260.h"

extern M2C_UNK D_8099017C;

void ObjGrassCarry_SetupIdle(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x19C) = &D_8099017C;
}

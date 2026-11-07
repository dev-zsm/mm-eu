// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0086.h"

extern M2C_UNK D_808A7088;

void ObjWturn_SetupIdle(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_808A7088;
}

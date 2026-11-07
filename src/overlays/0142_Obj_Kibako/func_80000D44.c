// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0142.h"

extern M2C_UNK D_8090B9F8;

void ObjKibako_SetupHeld(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_8090B9F8;
}

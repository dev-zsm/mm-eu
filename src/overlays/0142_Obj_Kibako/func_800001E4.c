// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0142.h"

void func_800001E4(ObjKibako *this, PlayState *play) {
    if ((M2C_FIELD(this, s8 *, 0x198) == 0) && (M2C_FIELD(this, s8 *, 0x199) != M2C_FIELD(play, s8 *, 0x186E0))) {
        M2C_FIELD(this, s8 *, 0x198) = 1;
    }
}

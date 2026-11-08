// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0523.h"

s32 ObjWarpstone_OpenedIdle(ObjWarpstone *this, PlayState *play) {
    M2C_FIELD(this, s16 *, 0x116) = 0xC01;
    return 0;
}

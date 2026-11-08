// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0159.h"

void func_800002B8(EnGoroiwa *this, PlayState *play) {
    M2C_FIELD(this, s8 *, 0x1E4) = (s8) (((s16) M2C_FIELD(this, s16 *, 0x14) >> 1) & 3);
}

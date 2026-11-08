// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0512.h"

s32 func_80000104(BgIkanaBlock *this, PlayState *play) {
    return (M2C_FIELD(this, u8 *, 0x17C) & 8) == 0;
}

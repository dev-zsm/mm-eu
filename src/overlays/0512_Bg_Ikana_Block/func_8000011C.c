// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0512.h"

s32 func_8000011C(BgIkanaBlock *this, PlayState *play) {
    return M2C_FIELD(this, s8 *, 0x17B) >= 0xB;
}

// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0448.h"

s32 EnGakufu_IsPlayerInRange(EnGakufu *this, PlayState *play) {
    if (M2C_FIELD(this, f32 *, 0x98) < 600.0f) {
        return 1;
    }
    return 0;
}

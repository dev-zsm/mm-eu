// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0403.h"

void TransitionWipe1_SetType(void *thisx, s32 type) {
    if (type == 1) {
        M2C_FIELD(thisx, u8 *, 8) = 1U;
    } else {
        M2C_FIELD(thisx, u8 *, 8) = 0U;
    }
    if (M2C_FIELD(thisx, u8 *, 8) != 0) {
        M2C_FIELD(thisx, s16 *, 0xE) = 0x14D;
        return;
    }
    M2C_FIELD(thisx, s16 *, 0xE) = 0x264;
}

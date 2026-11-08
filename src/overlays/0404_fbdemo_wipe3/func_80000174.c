// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0404.h"

void TransitionWipe3_UpdateScrollY(void *thisx, f32 scroll) {
    M2C_FIELD(thisx, s32 *, 0xC) = (s32) (500.0f * scroll);
}

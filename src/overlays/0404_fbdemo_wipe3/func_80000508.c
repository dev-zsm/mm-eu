// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0404.h"

void TransitionWipe3_SetEnvColor(void *thisx, u32 color) {
    M2C_FIELD(thisx, s32 *, 4) = color;
}

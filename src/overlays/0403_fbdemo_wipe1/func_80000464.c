// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0403.h"

void TransitionWipe1_SetEnvColor(void *thisx, u32 color) {
    M2C_FIELD(thisx, s32 *, 4) = color;
}

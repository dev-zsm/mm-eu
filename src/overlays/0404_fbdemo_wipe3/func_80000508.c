// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0404.h"

void TransitionWipe3_SetEnvColor(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 4) = arg1;
}

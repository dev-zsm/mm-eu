// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0405.h"

void TransitionWipe4_SetColor(s32 *arg0, s32 arg1) {
    *arg0 = arg1;
}

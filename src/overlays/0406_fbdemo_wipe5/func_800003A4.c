// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0406.h"

void TransitionWipe5_SetColor(s32 *arg0, s32 arg1) {
    *arg0 = arg1;
}

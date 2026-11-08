// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0405.h"

M2C_UNK func_800897D0(s32, M2C_UNK);                /* extern */

void * TransitionWipe4_Init(void *thisx) {
    func_800897D0(thisx, 0x28);
    return thisx;
}

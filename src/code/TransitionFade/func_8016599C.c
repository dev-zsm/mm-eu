// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

M2C_UNK func_800897D0(s32, M2C_UNK);                /* extern */

void * TransitionFade_Init(void *thisx) {
    func_800897D0(thisx, 0xC);
    return thisx;
}

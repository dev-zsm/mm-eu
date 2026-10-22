// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800897D0(s32, M2C_UNK);                /* extern */

s32 TransitionFade_Init(s32 arg0) {
    func_800897D0(arg0, 0xC);
    return arg0;
}

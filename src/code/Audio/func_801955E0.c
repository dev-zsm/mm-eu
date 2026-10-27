// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 func_800881B0(s32);                             /* extern */
M2C_UNK func_8008A780(s32, s32);                    /* extern */

void Audio_WritebackDCache(s32 arg0, s32 arg1) {
    s32 sp1C;

    sp1C = func_800881B0(1);
    func_8008A780(arg0, arg1);
    func_800881B0(sp1C);
}

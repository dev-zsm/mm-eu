// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Math_SmoothStepToS(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */

s32 Actor_TrackNone(s32 arg0, s32 arg1) {
    Math_SmoothStepToS(arg0 + 2, 0, 6, 0x1838, 0x64);
    Math_SmoothStepToS(arg0, 0, 6, 0x1838, 0x64);
    Math_SmoothStepToS(arg1 + 2, 0, 6, 0x1838, 0x64);
    Math_SmoothStepToS(arg1, 0, 6, 0x1838, 0x64);
    return 1;
}

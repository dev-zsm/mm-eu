// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Math_StepToIGet(s32 *, s32);                  /* extern */

s32 Math_StepToI(s32 *arg0, s32 arg1) {
    Math_StepToIGet(arg0, arg1);
    return arg1 == *arg0;
}

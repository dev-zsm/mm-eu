// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 func_8008ABB0();                                /* extern */
s32 func_80096670();                                /* extern */

s32 Sched_TaskFramebuffersValid(void *arg0, void *arg1) {
    s32 sp1C;
    s32 temp_v0;

    sp1C = func_8008ABB0();
    temp_v0 = func_80096670();
    if ((arg1 == NULL) || (M2C_FIELD(arg0, s32 *, 0x324) != 0) || ((temp_v0 == *M2C_FIELD(arg1, s32 **, 0xC)) && (temp_v0 != sp1C))) {
        return 0;
    }
    return 1;
}

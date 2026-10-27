// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80087CB0(s32, s32, M2C_UNK, void *);   /* extern */
M2C_UNK Sched_SetNextFramebufferFromTask(s32, void *);                 /* extern */

void Sched_TaskComplete(s32 arg0, void *arg1) {
    s32 temp_a0;

    if (!(M2C_FIELD(arg1, s32 *, 4) & 3)) {
        temp_a0 = M2C_FIELD(arg1, s32 *, 0x50);
        if (temp_a0 != 0) {
            func_80087CB0(temp_a0, M2C_FIELD(arg1, s32 *, 0x54), 1, arg1);
        }
        if (M2C_FIELD(arg1, s32 *, 8) & 0x40) {
            Sched_SetNextFramebufferFromTask(arg0, arg1);
        }
    }
}

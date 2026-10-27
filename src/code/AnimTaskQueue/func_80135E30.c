// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void *AnimTaskQueue_NewTask(s32, M2C_UNK);                  /* extern */
extern s32 D_801ED330;

void AnimTaskQueue_AddInterp(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4) {
    void *temp_v0;

    temp_v0 = AnimTaskQueue_NewTask(arg0 + 0x17104, 2);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s8 *, 4) = (s8) D_801ED330;
        M2C_FIELD(temp_v0, s8 *, 5) = (s8) arg1;
        M2C_FIELD(temp_v0, s32 *, 8) = arg2;
        M2C_FIELD(temp_v0, s32 *, 0xC) = arg3;
        M2C_FIELD(temp_v0, f32 *, 0x10) = arg4;
    }
}

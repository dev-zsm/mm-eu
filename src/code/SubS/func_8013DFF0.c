// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 func_80100304(s32);                             /* extern */

s32 SubS_CopyPointFromPathList(s32 arg0, s32 arg1, s32 arg2, void *arg3) {
    void *temp_v1;

    temp_v1 = func_80100304(M2C_FIELD(((arg1 * 8) + arg0), s32 *, 4)) + (arg2 * 6);
    M2C_FIELD(arg3, f32 *, 0) = (f32) M2C_FIELD(temp_v1, s16 *, 0);
    M2C_FIELD(arg3, f32 *, 4) = (f32) M2C_FIELD(temp_v1, s16 *, 2);
    M2C_FIELD(arg3, f32 *, 8) = (f32) M2C_FIELD(temp_v1, s16 *, 4);
    return 0;
}

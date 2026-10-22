// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 Animation_GetLastFrame(s32);                             /* extern */
M2C_UNK PlayerAnimation_Change(s32, s32, s32, s32, f32, f32, s32, f32); /* extern */

void PlayerAnimation_PlayLoopSetSpeed(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    PlayerAnimation_Change(arg0, arg1, arg2, arg3, 0.0f, (f32) Animation_GetLastFrame(arg2), 0, 0.0f);
}

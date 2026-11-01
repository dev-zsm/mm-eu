// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 Animation_GetLastFrame(s32);                             /* extern */
M2C_UNK PlayerAnimation_Change(s32, s32, s32, M2C_UNK, f32, f32, s32, f32); /* extern */

void PlayerAnimation_PlayLoop(s32 arg0, s32 arg1, s32 arg2) {
    PlayerAnimation_Change(arg0, arg1, arg2, 0x3F800000, 0.0f, (f32) Animation_GetLastFrame(arg2), 0, 0.0f);
}

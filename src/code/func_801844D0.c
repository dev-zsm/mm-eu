// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 func_80100304(s32);                             /* extern */
M2C_UNK FrameCtrl_Init(void *);                      /* extern */
M2C_UNK Keyframe_ResetFlex(void *);                      /* extern */

void Keyframe_InitFlex(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    Keyframe_ResetFlex(arg0);
    FrameCtrl_Init(arg0);
    M2C_FIELD(arg0, s32 *, 0x18) = func_80100304(arg1);
    M2C_FIELD(arg0, s32 *, 0x1C) = func_80100304(arg2);
    M2C_FIELD(arg0, s32 *, 0x28) = arg3;
    M2C_FIELD(arg0, s32 *, 0x2C) = arg4;
    M2C_FIELD(arg0, s32 *, 0x20) = arg5;
}

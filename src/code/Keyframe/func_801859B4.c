// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void *func_80100304(s32);                           /* extern */
M2C_UNK FrameCtrl_SetProperties(void *, s32, s32, f32, f32, f32, s32); /* extern */

void Keyframe_StandardChangeAnim(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5, f32 arg6, f32 arg7, s32 arg8, s32 arg9) {
    void *temp_v0;

    M2C_FIELD(arg0, f32 *, 0x20) = arg7;
    M2C_FIELD(arg0, void **, 0x18) = func_80100304(arg1);
    temp_v0 = func_80100304(arg2);
    M2C_FIELD(arg0, void **, 0x1C) = temp_v0;
    FrameCtrl_SetProperties(arg0, arg3, arg4, (f32) M2C_FIELD(temp_v0, s16 *, 0x12), arg5, arg6, arg8);
    M2C_FIELD(arg0, s32 *, 0x2C) = arg9;
}

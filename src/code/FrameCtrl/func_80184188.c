// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void FrameCtrl_SetProperties(struct FrameControl *frameCtrl, f32 startTime, f32 endTime, f32 frameCount, f32 t, f32 speed, s32 animMode) {
    M2C_FIELD(frameCtrl, f32 *, 0) = startTime;
    if (endTime < 1.0f) {
        M2C_FIELD(frameCtrl, f32 *, 4) = frameCount;
    } else {
        M2C_FIELD(frameCtrl, f32 *, 4) = endTime;
    }
    M2C_FIELD(frameCtrl, f32 *, 8) = frameCount;
    M2C_FIELD(frameCtrl, f32 *, 0xC) = speed;
    M2C_FIELD(frameCtrl, f32 *, 0x10) = t;
    M2C_FIELD(frameCtrl, s32 *, 0x14) = animMode;
}

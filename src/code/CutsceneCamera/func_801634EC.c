#include "types.h"

typedef struct {
    u8 pad0[2];
    s16 duration;
} CutsceneCameraKeyframe;

typedef struct {
    u8 pad0[0x24];
    s16 curFrame;
    s16 unk26;
    s16 unk28;
    u8 pad2A[3];
    u8 unk2D;
} CutsceneCameraState;

s32 CutsceneCamera_Interp_None(s32 arg0, s32 arg1, s32 arg2, CutsceneCameraKeyframe *keyframe, s32 arg4,
                               CutsceneCameraState *state) {
    if (state->unk2D != 0) {
        state->unk2D = 0;
        state->unk26 = 0;
        state->curFrame = 0;
        state->unk28 = 1;
    }
    state->curFrame++;
    if (state->curFrame >= keyframe->duration) {
        state->unk2D = 7;
        return 1;
    }
    return 0;
}

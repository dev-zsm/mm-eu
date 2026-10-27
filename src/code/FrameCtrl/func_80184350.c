#include "types.h"

typedef struct {
    f32 unk0;
    f32 unk4;
    u8 pad8[8];
    f32 unk10;
} FrameCtrl4350;

s32 FrameCtrl_PassCheck(FrameCtrl4350 *, f32, f32 *);

s32 FrameCtrl_UpdateLoop(FrameCtrl4350 *frameCtrl) {
    f32 t;

    if (FrameCtrl_PassCheck(frameCtrl, frameCtrl->unk4, &t)) {
        frameCtrl->unk10 = frameCtrl->unk0 + t;
        return 2;
    }
    if (FrameCtrl_PassCheck(frameCtrl, frameCtrl->unk0, &t)) {
        frameCtrl->unk10 = frameCtrl->unk4 + t;
        return 2;
    }
    return 0;
}

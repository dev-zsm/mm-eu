#include "types.h"

typedef struct {
    f32 unk0;
    f32 unk4;
    u8 pad8[8];
    f32 unk10;
} FrameCtrl;

extern s32 FrameCtrl_PassCheck(FrameCtrl* ctrl, f32 a, s32* out);

s32 FrameCtrl_UpdateOnce(FrameCtrl* ctrl) {
    s32 sp1C;

    if (ctrl->unk10 == ctrl->unk4) {
        return 1;
    }
    if (FrameCtrl_PassCheck(ctrl, ctrl->unk4, &sp1C) != 0) {
        ctrl->unk10 = ctrl->unk4;
        return 1;
    }
    if (FrameCtrl_PassCheck(ctrl, ctrl->unk0, &sp1C) != 0) {
        ctrl->unk10 = ctrl->unk4;
        return 1;
    }
    return 0;
}

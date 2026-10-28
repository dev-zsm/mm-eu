#include "types.h"

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    s32 unk14;
} Ctrl;

extern s32 FrameCtrl_UpdateOnce(Ctrl *);
extern s32 FrameCtrl_UpdateLoop(Ctrl *);

s32 FrameCtrl_Update(Ctrl *c) {
    s32 r;
    f32 d;

    if (c->unk14 == 0) {
        r = FrameCtrl_UpdateOnce(c);
    } else {
        r = FrameCtrl_UpdateLoop(c);
    }
    if (r == 0) {
        if (c->unk0 < c->unk4) {
            d = c->unkC;
        } else {
            d = -c->unkC;
        }
        c->unk10 += d * 1.5f;
    }
    if (c->unk10 < 1.0f) {
        c->unk10 = c->unk10 - 1.0f + c->unk8;
    } else if (c->unk8 < c->unk10) {
        c->unk10 = c->unk10 - c->unk8 + 1.0f;
    }
    return r;
}

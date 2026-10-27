#include "types.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Viewport;

typedef struct {
    u8 pad0[8];
    Viewport viewport;
    u8 pad18[0x148];
    u32 flags;
} View;

void View_SetViewport(View *view, Viewport *viewport) {
    view->viewport = *viewport;
    view->flags |= 2;
}

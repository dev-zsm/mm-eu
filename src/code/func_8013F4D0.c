#include "types.h"

typedef struct {
    u8 pad0[0x18];
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    u8 pad28[0x138];
    u32 flags;
} View;

void View_SetOrtho(View *view, f32 arg1, f32 arg2, f32 arg3) {
    view->unk18 = arg1;
    view->unk1C = arg2;
    view->unk20 = arg3;
    view->unk24 = 1.0f;
    view->flags |= 8;
}

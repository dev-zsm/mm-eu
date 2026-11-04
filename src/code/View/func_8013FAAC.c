#include "types.h"

typedef struct {
    /* 0x000 */ u8 pad0[0x160];
    /* 0x160 */ s32 flagsMask;
} View;

extern void View_ApplyOrtho(View *view);
extern void View_ApplyPerspective(View *view);

void View_Apply(View *view, s32 options) {
    options = (view->flagsMask & options) | (options >> 4);
    if (options & 8) {
        View_ApplyOrtho(view);
    } else {
        View_ApplyPerspective(view);
    }
}

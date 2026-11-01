#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
} View;

void View_SetScissor(Gfx **gfxp, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

// One-line macro: the ROM's scheduling depends on the command being emitted from a single source line.
#define GFX_PIPE_SYNC(pkt) { Gfx *_g = (pkt); _g->w1 = 0; _g->w0 = 0xE7000000; }

void View_ClearScissor(View *view, Gfx **gfxp) {
    Gfx *gfx = *gfxp;
    s32 arg1 = view->unk10;

    GFX_PIPE_SYNC(gfx++);
    View_SetScissor(&gfx, arg1, view->unk8, view->unk14, view->unkC);
    *gfxp = gfx;
}

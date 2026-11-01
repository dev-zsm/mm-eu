#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u8 pad0[0x2C0];
    Gfx *polyXlu;
} GfxCtx;

typedef struct {
    GfxCtx *gfxCtx;
} PlayState;

typedef struct {
    u32 pad0;
    u32 unk4;
    u32 unk8;
    u32 pad[6];
} Entry;

extern Entry D_801BBCA0[];

void func_8012C78C(GfxCtx *gfxCtx);
u32 Matrix_Finalize(GfxCtx *gfxCtx);

void GetItem_DrawXlu01(PlayState *play, s16 drawId) {
    GfxCtx *gfxCtx = play->gfxCtx;
    Gfx *dl;
    Entry *e;

    func_8012C78C(gfxCtx);
    dl = gfxCtx->polyXlu++;
    dl->w0 = 0xDA380003;
    dl->w1 = Matrix_Finalize(play->gfxCtx);
    dl = gfxCtx->polyXlu++;
    e = &D_801BBCA0[drawId];
    dl->w0 = 0xDE000000;
    dl->w1 = e->unk4;
    dl = gfxCtx->polyXlu++;
    dl->w0 = 0xDE000000;
    dl->w1 = e->unk8;
}

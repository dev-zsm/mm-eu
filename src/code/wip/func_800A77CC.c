#include "types.h"

typedef struct { u32 w0; u32 w1; } Gfx;
typedef struct {
    u8 pad0[0x2B0];
    Gfx *polyOpa;
} GfxCtx;
typedef struct {
    GfxCtx *gfx;
} Play;
typedef struct {
    u8 pad0[0x1C];
    s16 params;
} Actor;

extern u8 D_40622C0[];
extern u32 D_801AEDF0[];
extern void Gfx_SetupDL25_Opa();
extern void func_800B7DD4();
extern u32 func_80100304();
extern u32 Matrix_Finalize();

void EnItem00_DrawRupee(Actor *actor, Play *play) {
    GfxCtx *gfx;
    s32 idx;
    Gfx *dl;

    Gfx_SetupDL25_Opa(gfx = play->gfx);
    func_800B7DD4(actor, play, 0);
    if (actor->params < 3) {
        idx = actor->params;
    } else {
        idx = actor->params - 0x10;
    }
    dl = gfx->polyOpa++;
    dl->w0 = 0xDA380003;
    dl->w1 = Matrix_Finalize(play->gfx, idx);
    dl = gfx->polyOpa++;
    dl->w0 = 0xDB060020;
    dl->w1 = func_80100304(D_801AEDF0[idx], idx);
    dl = gfx->polyOpa++;
    dl->w0 = 0xDE000000; dl->w1 = (u32)D_40622C0;
}

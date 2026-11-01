// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u8 pad0[0x2B0];
    Gfx *polyOpa;
} GfxCtx;

typedef struct {
    u8 pad0[2];
    u8 unk2;
    u8 pad3;
    s32 unk4;
    u8 pad8[0x18];
    s32 unk20;
} Obj;

extern u8 D_801C29C0[];
void Gfx_SetupDL25_Opa(GfxCtx *gfx);
Gfx *SkelAnime_DrawFlex(GfxCtx **ctx, s32 a, s32 b, u8 c, s32 d, s32 e, s32 f, Gfx *g);

void func_800BD764(GfxCtx **arg0, Obj *arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5) {
    GfxCtx *gfx;
    Gfx *g;

    gfx = *arg0;
    Gfx_SetupDL25_Opa(gfx);
    g = gfx->polyOpa++;
    g->w0 = 0xFB000000;
    g->w1 = arg5 & 0xFF;
    g = gfx->polyOpa++;
    g->w1 = (u32)D_801C29C0;
    g->w0 = 0xDB060030;
    gfx->polyOpa = SkelAnime_DrawFlex(arg0, arg1->unk4, arg1->unk20, arg1->unk2, arg2, arg3, arg4, gfx->polyOpa);
}

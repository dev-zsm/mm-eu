#include "types.h"
typedef struct { u32 w0; u32 w1; } Gfx;
typedef struct { u8 pad0[0x2A0]; Gfx *unk2A0; u8 pad2A4[0xC]; Gfx *unk2B0; } Gfxctx;
typedef struct { Gfxctx *gfx; u8 pad[0x16810 - 4]; u16 unk16810; } Ctx;
Gfx *Gfx_Open(Gfx *);
void Gfx_Close(Gfx *, Gfx *);
s32 Play_InCsMode(Ctx *);
void func_80154748(Ctx *, Gfx **);
void func_80156C8C(Ctx *a0) {
    Gfxctx *g;
    Gfx *sp3C;
    Gfx *sp38;
    Gfx *t;
    g = a0->gfx;
    sp38 = g->unk2B0;
    sp3C = Gfx_Open(sp38);
    t = g->unk2A0++;
    t->w0 = 0xDE000000;
    t->w1 = (u32)sp3C;
    if (a0->unk16810 != 0x5E6 || Play_InCsMode(a0) == 0) {
        func_80154748(a0, &sp3C);
    }
    t = sp3C++;
    t->w1 = 0;
    t->w0 = 0xDF000000;
    Gfx_Close(sp38, sp3C);
    g->unk2B0 = sp3C;
}

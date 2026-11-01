#include "types.h"
typedef struct { u32 w0; u32 w1; } Gfx;
typedef struct { u8 pad[0x2B0]; Gfx *p; } GC;
typedef struct { GC *gfx; } PS;
typedef struct { u8 pad[4]; u32 a; u32 b; u8 pad2[0x24 - 12]; } E;
extern E D_801BBCA0[];
extern void Gfx_SetupDL25_Opa(GC *);
extern u32 Matrix_Finalize(GC *);
void GetItem_DrawOpa01(PS *a0, s16 a1) {
    s32 pad;
    GC *gfx = a0->gfx;
    Gfx *g;
    E *e;
    Gfx_SetupDL25_Opa(a0->gfx);
    g = gfx->p++;
    g->w0 = 0xDA380003;
    g->w1 = Matrix_Finalize(a0->gfx);
    g = gfx->p++;
    g->w0 = 0xDE000000;
    e = &D_801BBCA0[a1];
    g->w1 = e->a;
    g = gfx->p++;
    g->w0 = 0xDE000000;
    g->w1 = e->b;
}

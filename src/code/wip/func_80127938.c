#include "types.h"
typedef struct { u32 w0; u32 w1; } Gfx;
typedef struct { u8 pad[0x2C0]; Gfx *p; } GC;
typedef struct { GC *gfx; } PS;
extern u8 D_6011AB8[];
extern void func_80123054(PS *, s32, s32, u8);
extern u32 Matrix_Finalize(GC *);
void func_80127938(PS *a0, s32 a1, u8 a2) {
    GC *gfx = a0->gfx;
    Gfx *g;
    g = gfx->p++;
    g->w0 = 0xDA380003;
    g->w1 = Matrix_Finalize(a0->gfx);
    g = gfx->p++;
    g->w0 = 0xFB000000;
    g->w1 = a2 | 0xFF000000;
    g = gfx->p++;
    g->w0 = 0xDE000000;
    g->w1 = (u32)D_6011AB8;
    func_80123054(a0, a1 + 0x3D0, 3, a2);
}

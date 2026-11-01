#include "types.h"
typedef struct { u32 w0; u32 w1; } Gfx;
typedef struct { u8 pad[0x2B0]; Gfx *opa; u8 pad2B4[0xC]; Gfx *xlu; } GC;
extern s32 D_801ED324;
s32 AnimatedMat_TexScroll(GC **, s32);
void AnimatedMat_DrawTexScroll(GC **pgc, s32 a1, s32 a2) {
    s32 v0 = AnimatedMat_TexScroll(pgc, a2);
    GC *gc = *pgc;
    Gfx *g;
    if (D_801ED324 & 1) {
        g = gc->opa++;
        g->w0 = ((a1 * 4) & 0xFFFF) | 0xDB060000;
        g->w1 = v0;
    }
    if (D_801ED324 & 2) {
        g = gc->xlu++;
        g->w1 = v0;
        g->w0 = ((a1 * 4) & 0xFFFF) | 0xDB060000;
    }
}

#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} GfxDD44;

typedef struct {
    u8 pad0[0x2B0];
    GfxDD44 *polyOpa;
} GfxCtxDD44;

extern u8 D_801C2060[];

u32 Matrix_Finalize(GfxCtxDD44 *);

void Gfx_DrawDListOpa(GfxCtxDD44 **play, void *dList) {
    GfxDD44 *p;
    GfxCtxDD44 *gfxCtx = *play;

    if (1) { /* scope only fixes register allocation */
        p = gfxCtx->polyOpa;
        p[0].w1 = (u32)D_801C2060;
        p[0].w0 = 0xDE000000;
        p[1].w0 = 0xDA380003;
        p[1].w1 = Matrix_Finalize(*play);
        p[2].w0 = 0xDE000000;
        p[2].w1 = (u32)dList;
        gfxCtx->polyOpa = p + 3;
    }
}

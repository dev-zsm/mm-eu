#include "types.h"

typedef struct { u32 w0; u32 w1; } Gfx;
typedef struct {
    u8 pad0[0x2B0];
    Gfx *polyOpa;
} GfxCtx;

typedef struct {
    u8 pad0[0xC];
    s32 unkC;
} Obj;

extern u8 D_801ED340[];
extern void *func_80100304();
extern u32 SkinMatrix_MtxFToNewMtx();

void Skin_DrawLimb(GfxCtx *gfx, s32 **a1, s32 a2, s32 a3) {
    s32 *tbl;
    s32 t0;
    u32 r;
    Gfx *dl;

    t0 = a3;
    tbl = func_80100304(**a1);
    t0 = a3;
    if (a3 == 0) {
        t0 = ((Obj *)func_80100304(tbl[a2]))->unkC;
    }
    if (t0 != 0) {
        r = SkinMatrix_MtxFToNewMtx(gfx, D_801ED340 + (a2 << 6));
        if (r != 0) {
            dl = gfx->polyOpa++;
            dl->w1 = r;
            dl->w0 = 0xDA380000;
            dl = gfx->polyOpa++;
            dl->w1 = t0;
            dl->w0 = 0xDE000000;
            dl = gfx->polyOpa++;
            dl->w1 = 0x40;
            dl->w0 = 0xD8380002;
            dl = gfx->polyOpa++;
            dl->w1 = 0;
            dl->w0 = 0xE7000000;
        }
    }
}

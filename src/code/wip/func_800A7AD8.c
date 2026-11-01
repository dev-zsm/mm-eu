#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx_800A7AD8;

typedef struct {
    /* 0x000 */ u8 pad0[0x2C0];
    /* 0x2C0 */ Gfx_800A7AD8 *polyOpa;
} GfxCtx_800A7AD8;

extern void func_8012C78C(GfxCtx_800A7AD8 *);
extern void func_800B7E9C(s32, GfxCtx_800A7AD8 **, s32);
extern u32 Matrix_Finalize(GfxCtx_800A7AD8 *);
extern u8 D_405AAB0[];

void EnItem00_DrawHeartPiece(s32 arg0, GfxCtx_800A7AD8 **arg1) {
    s32 pad[2];
    GfxCtx_800A7AD8 *gfxCtx;
    Gfx_800A7AD8 *dl;


    func_8012C78C(gfxCtx = *arg1);
    func_800B7E9C(arg0, arg1, 0);
    dl = gfxCtx->polyOpa++;
    dl->w0 = 0xDA380003;
    dl->w1 = Matrix_Finalize(*arg1);
    dl = gfxCtx->polyOpa++;
    dl->w1 = (u32)D_405AAB0;
    dl->w0 = 0xDE000000;
}

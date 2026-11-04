#include "types.h"

typedef struct {
    u8 m[0x40];
} Mtx;

typedef struct {
    u8 pad0[0x2B4];
    Mtx *poolEnd;
} GraphicsContext;

extern void SkinMatrix_MtxFToMtx(void *mf, Mtx *mtx);

Mtx *SkinMatrix_MtxFToNewMtx(GraphicsContext *gfxCtx, void *mf) {
    s32 pad; // keeps the spill slot of mtx at 0x18
    Mtx *mtx = gfxCtx->poolEnd - 1;

    gfxCtx->poolEnd = mtx;
    if (mtx == NULL) {
        return NULL;
    }
    SkinMatrix_MtxFToMtx(mf, mtx);
    return mtx;
}

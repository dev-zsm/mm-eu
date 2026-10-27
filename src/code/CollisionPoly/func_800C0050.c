#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ void *vtxList;
} CollisionHeader;

typedef struct {
    /* 0x0000 */ CollisionHeader *colHeader;
    /* 0x0004 */ u8 pad4[0x1440];
    /* 0x1444 */ void *dynaVtxList;
} CollisionContext;

extern void CollisionPoly_GetVertices(void *, void *, Vec3f *);

void CollisionPoly_GetVerticesByBgId(void *poly, s32 bgId, CollisionContext *colCtx, Vec3f *dest) {
    void *vtxList;

    if ((poly == NULL) || (bgId > 50) || (dest == NULL)) {
        if (dest != NULL) {
            // dest[2].x and dest[2].y are left untouched in the ROM
            dest[0].x = dest[0].y = dest[0].z = dest[1].x = dest[1].y = dest[1].z = dest[2].z = 0.0f;
        }
    } else {
        if (bgId == 50) {
            vtxList = colCtx->colHeader->vtxList;
        } else {
            vtxList = colCtx->dynaVtxList;
        }
        CollisionPoly_GetVertices(poly, vtxList, dest);
    }
}

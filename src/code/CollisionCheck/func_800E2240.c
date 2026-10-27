#include "types.h"

typedef struct {
    /* 0x000 */ s16 sacFlags;
    /* 0x002 */ u16 flags;
    /* 0x004 */ void *colAt[50];
    /* 0x0CC */ s32 colAtCount;
    /* 0x0D0 */ void *colAc[60];
    /* 0x1C0 */ s32 colAcCount;
    /* 0x1C4 */ void *colOc[50];
    /* 0x28C */ s32 colOcCount;
    /* 0x290 */ void *colLine[3];
} CollisionCheckContext;

void CollisionCheck_ClearContext(s32 play, CollisionCheckContext *colCtx) {
    void **p;

    if (!(colCtx->flags & 1)) {
        colCtx->sacFlags = 0;
        colCtx->colAtCount = 0;
        colCtx->colAcCount = 0;
        colCtx->colOcCount = 0;
        for (p = colCtx->colAt; p < colCtx->colAt + 50; p++) {
            *p = 0;
        }
        for (p = colCtx->colAc; p < colCtx->colAc + 60; p++) {
            *p = 0;
        }
        for (p = colCtx->colOc; p < colCtx->colOc + 50; p++) {
            *p = 0;
        }
        for (p = colCtx->colLine; p < colCtx->colLine + 3; p++) {
            *p = 0;
        }
    }
}

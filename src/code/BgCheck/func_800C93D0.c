#include "types.h"

typedef struct {
    u8 pad0[8];
    u8 *polyCheckTbl;
} CollisionCtx;

void BgCheck_ResetPolyCheckTbl(CollisionCtx *colCtx, u32 count) {
    u8 *p;
    u8 *end = colCtx->polyCheckTbl + count;

    for (p = colCtx->polyCheckTbl; p < end; p++) {
        *p = 0;
    }
}

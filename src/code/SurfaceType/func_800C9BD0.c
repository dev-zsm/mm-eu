#include "types.h"

typedef struct {
    u8 pad0[0x146C];
    u32 flags;
} CollisionContext;

extern u32 SurfaceType_GetData(CollisionContext *colCtx, s32 poly, s32 bgId, s32 index);

s32 SurfaceType_GetConveyorDirection(CollisionContext *colCtx, s32 poly, s32 bgId) {
    u32 data = SurfaceType_GetData(colCtx, poly, bgId, 1);
    s32 dir = data >> 21;

    if (colCtx->flags & 1) {
        dir += 0x20;
    }
    return dir & 0x3F;
}

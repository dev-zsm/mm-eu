#include "types.h"

typedef struct {
    u8 flags;
    u8 pad1[0x138B];
    u16 bgActorFlags[1];
} CollisionContext;

s32 DynaPoly_IsBgIdBgActor(s32 bgId);

void DynaPoly_EnableFloorCollision(s32 arg0, CollisionContext *colCtx, s32 bgId) {
    if (DynaPoly_IsBgIdBgActor(bgId)) {
        colCtx->bgActorFlags[bgId] &= ~0x20;
        colCtx->flags |= 1;
    }
}

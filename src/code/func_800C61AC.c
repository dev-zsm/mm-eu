#include "types.h"

typedef struct {
    u8 flags;
    u8 pad1[0x138B];
    u16 unk138C[1];
} Ctx;

extern s32 DynaPoly_IsBgIdBgActor(s32 index);

void DynaPoly_DisableFloorCollision(void *play, Ctx *ctx, s32 index) {
    if (DynaPoly_IsBgIdBgActor(index)) {
        ctx->unk138C[index] |= 0x20;
        ctx->flags |= 1;
    }
}

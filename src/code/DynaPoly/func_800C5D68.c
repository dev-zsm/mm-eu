#include "types.h"

typedef struct {
    s32 w[8];
} Transform;

typedef struct {
    u8 pad0[0x14];
    Transform prev;
    Transform cur;
} BgActor;

void DynaPoly_SetBgActorPrevTransform(s32 arg0, BgActor *bgActor) {
    bgActor->prev = bgActor->cur;
}

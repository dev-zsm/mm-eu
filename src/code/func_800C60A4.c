#include "types.h"

typedef struct {
    u8 flags;
    u8 pad1[0x138B];
    u16 actorFlags[1];
} DynaCollisionContext;

extern s32 DynaPoly_IsBgIdBgActor(s32 index);

void DynaPoly_EnableCollision(void *play, DynaCollisionContext *dyna, s32 index) {
    if (DynaPoly_IsBgIdBgActor(index)) {
        dyna->actorFlags[index] &= ~4;
        dyna->flags |= 1;
    }
}

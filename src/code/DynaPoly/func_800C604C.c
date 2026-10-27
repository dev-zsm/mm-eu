#include "types.h"

typedef struct {
    u8 flags;
    u8 pad[0x138B];
    u16 entryFlags[1];
} DynaCollision;

extern s32 DynaPoly_IsBgIdBgActor(s32 index);

void DynaPoly_DisableCollision(s32 a0, DynaCollision *dyna, s32 index) {
    if (DynaPoly_IsBgIdBgActor(index) != 0) {
        dyna->entryFlags[index] |= 4;
        dyna->flags |= 1;
    }
}

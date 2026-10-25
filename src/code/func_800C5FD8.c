#include "types.h"

typedef struct {
    u8 pad0[0x54];
    void *actor;
    u8 pad58[0x64 - 0x58];
} DynaEntry;

typedef struct {
    DynaEntry entries[1];
    u8 pad[0x13DC - 0x64];
    u16 flags[1];
} DynaCollisionContext;

s32 DynaPoly_IsBgIdBgActor(s32 bgId);

void *DynaPoly_GetActor(DynaCollisionContext *dyna, s32 bgId) {
    if (DynaPoly_IsBgIdBgActor(bgId) == 0 || !(dyna->flags[bgId] & 1) || (dyna->flags[bgId] & 2)) {
        return NULL;
    }
    return dyna->entries[bgId].actor;
}

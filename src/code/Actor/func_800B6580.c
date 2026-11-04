#include "types.h"

typedef struct {
    u32 segment;
    char pad4[0x40];
} ObjectEntry;

typedef struct {
    char pad0[0x17D98];
    ObjectEntry entries[1];
} ObjectContext;

typedef struct {
    char pad0[0x1E];
    s8 objectIndex;
} Actor;

extern u32 D_801EFA18;

void Actor_SetObjectDependency(ObjectContext *objCtx, Actor *actor) {
    D_801EFA18 = objCtx->entries[actor->objectIndex].segment + 0x80000000;
}

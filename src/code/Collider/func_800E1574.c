#include "types.h"

typedef struct {
    u8 pad[0x5C];
} TrisElem;

typedef struct {
    u8 pad0[0x18];
    s32 count;
    TrisElem* elem;
} Tris;

extern void Collider_DestroyBase(void* play, Tris* tris);
extern void Collider_DestroyTrisElement(void* play, TrisElem* elem);

s32 Collider_DestroyTris(void* play, Tris* tris) {
    TrisElem* j;

    Collider_DestroyBase(play, tris);
    for (j = tris->elem; j < tris->elem + tris->count; j++) {
        Collider_DestroyTrisElement(play, j);
    }
    tris->count = 0;
    tris->elem = NULL;
    return 1;
}

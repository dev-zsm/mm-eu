#include "types.h"
typedef struct { u8 pad0[0x18]; s32 count; u8 *elem; } Tris;
s32 Collider_DestroyBase(void *a, void *b);
s32 Collider_DestroyTrisElement(void *a, void *b);
void ZeldaArena_Free(void *a);
s32 Collider_FreeTris(void *play, Tris *tris) {
    u8 *e;
    Collider_DestroyBase(play, tris);
    for (e = tris->elem; e < tris->elem + tris->count * 0x5C; e += 0x5C) {
        Collider_DestroyTrisElement(play, e);
    }
    tris->count = 0;
    if (tris->elem != 0) {
        ZeldaArena_Free(tris->elem);
    }
    tris->elem = 0;
    return 1;
}

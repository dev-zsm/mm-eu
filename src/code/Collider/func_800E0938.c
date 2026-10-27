#include "types.h"

typedef struct { u8 pad0[0x40]; } Elem;
typedef struct { u8 pad0[0x18]; s32 count; Elem *elements; } Sph;

extern void Collider_DestroyBase(void *play, Sph *sph);
extern void Collider_DestroyJntSphElement(void *play, Elem *elem);
extern void ZeldaArena_Free(void *);

s32 Collider_FreeJntSph(void *play, Sph *sph) {
    Elem *e;

    Collider_DestroyBase(play, sph);
    for (e = sph->elements; e < sph->elements + sph->count; e++) {
        Collider_DestroyJntSphElement(play, e);
    }
    sph->count = 0;
    if (sph->elements != NULL) {
        ZeldaArena_Free(sph->elements);
    }
    sph->elements = NULL;
    return 1;
}

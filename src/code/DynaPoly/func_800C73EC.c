#include "types.h"

typedef struct {
    /* 0x0000 */ u8 pad0[4];
    /* 0x0004 */ u8 actors[50][100];
    /* 0x138C */ u16 flags[50];
} DynaCtx;

extern void DynaPoly_SetBgActorPrevTransform(s32, void *);

void DynaPoly_UpdateBgActorTransforms(s32 a0, DynaCtx *a1) {
    s32 i;

    for (i = 0; i < 50; i++) {
        if (a1->flags[i] & 1) {
            DynaPoly_SetBgActorPrevTransform(a0, a1->actors[i]);
        }
    }
}

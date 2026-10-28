#include "types.h"

typedef struct { void *actor; u8 pad4[0xD]; u8 flags; u8 pad12[3]; u8 type; } Collider;
typedef struct { u8 pad0[0xCC]; s32 count; Collider *list[1]; } CollisionCheckContext;
typedef void (*HitFunc)(s32, CollisionCheckContext *, Collider *);
extern HitFunc D_801BAED8[];

void CollisionCheck_SetHitEffects(s32 play, CollisionCheckContext *colCtx) {
    Collider **col;

    for (col = colCtx->list; col < &colCtx->list[colCtx->count]; col++) {
        if (*col != NULL && ((*col)->flags & 1) && ((*col)->actor == NULL || *(s32 *)((u8 *)(*col)->actor + 0x138) != 0)) {
            D_801BAED8[(*col)->type](play, colCtx, *col);
        }
    }
}

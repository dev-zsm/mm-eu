#include "types.h"

typedef struct {
    u8 pad[0x138];
    s32 unk138;
} ColActor;

typedef struct {
    ColActor *actor;
    u8 pad4[0xC];
    u8 atFlags;
} Collider;

typedef struct {
    /* 0x000 */ s16 sacFlags;
    /* 0x002 */ u16 flags;
    /* 0x004 */ Collider *colAt[50];
    /* 0x0CC */ s32 colAtCount;
} CollisionCheckContext;

void CollisionCheck_AC(s32 play, CollisionCheckContext *colCtx, Collider *col);
void CollisionCheck_SetHitEffects(s32 play, CollisionCheckContext *colCtx);

void CollisionCheck_AT(s32 play, CollisionCheckContext *colCtx) {
    Collider **p;
    Collider *col;

    if (colCtx->sacFlags != 0) {
        if (colCtx->colAtCount != 0) {
            for (p = colCtx->colAt; p < colCtx->colAt + colCtx->sacFlags; p++) {
                col = *p;
                if (col == NULL) {
                    continue;
                }
                if (!(col->atFlags & 1)) {
                    continue;
                }
                if (col->actor == NULL || col->actor->unk138 != 0) {
                    CollisionCheck_AC(play, colCtx, col);
                }
            }
            CollisionCheck_SetHitEffects(play, colCtx);
        }
    }
}

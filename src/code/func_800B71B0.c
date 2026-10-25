#include "types.h"

typedef struct {
    u8 pad0[0xBE];
    s16 unkBE;
} ActorFacing;

extern s16 Actor_WorldYawTowardActor(void *a, void *b);

s32 Actor_ActorAIsFacingActorB(ActorFacing *actorA, void *actorB, s16 maxDiff) {
    s16 diff = Actor_WorldYawTowardActor(actorA, actorB) - actorA->unkBE;
    s32 absDiff;

    if (diff < 0) {
        absDiff = -diff;
    } else {
        absDiff = diff;
    }
    if (absDiff < maxDiff) {
        return 1;
    }
    return 0;
}

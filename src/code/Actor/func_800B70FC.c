#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[0xBE];
    /* 0xBE */ s16 yaw;
} Actor;

extern s16 Actor_WorldYawTowardActor(Actor *from, Actor *to);

s32 Actor_ActorBIsFacingActorA(Actor *actorA, Actor *actorB, s16 maxAngle) {
    s16 diff = (s16)(Actor_WorldYawTowardActor(actorA, actorB) + 0x8000) - actorB->yaw;
    s32 absDiff;

    if (diff < 0) {
        absDiff = -diff;
    } else {
        absDiff = diff;
    }
    if (absDiff < maxAngle) {
        return 1;
    }
    return 0;
}

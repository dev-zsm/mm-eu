#include "types.h"

extern f32 Actor_WorldDistXYZToActor(void *a, void *b);
extern s16 Actor_WorldYawTowardActor(void *a, void *b);

s32 Actor_ActorAIsFacingAndNearActorB(void *a, void *b, f32 range, s16 maxAngle) {
    s16 diff;
    s32 abs;

    if (Actor_WorldDistXYZToActor(a, b) < range) {
        diff = Actor_WorldYawTowardActor(a, b) - *(s16 *)((u8 *)a + 0xBE);
        if (diff < 0) {
            abs = -diff;
        } else {
            abs = diff;
        }
        if (abs < maxAngle) {
            return 1;
        }
    }
    return 0;
}

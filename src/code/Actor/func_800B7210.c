// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"

typedef struct {
    u8 pad0[0x92];
    s16 yawTowardsPlayer;
    u8 pad94[4];
    f32 unk98;
    f32 unk9C;
    u8 padA0[0xBE - 0xA0];
    s16 shapeRotY;
} Actor;

float sqrtf(float);
#pragma intrinsic (sqrtf)

s32 Actor_IsFacingAndNearPlayer(Actor *actor, f32 range, s16 maxAngle) {
    s16 yawDiff = actor->yawTowardsPlayer - actor->shapeRotY;
    s32 absYawDiff;

    if (yawDiff < 0) {
        absYawDiff = -yawDiff;
    } else {
        absYawDiff = yawDiff;
    }
    if (absYawDiff < maxAngle) {
        f32 dist = sqrtf(actor->unk98 * actor->unk98 + actor->unk9C * actor->unk9C);

        if (dist < range) {
            return 1;
        }
    }
    return 0;
}

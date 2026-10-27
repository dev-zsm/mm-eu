#include "types.h"

typedef struct {
    u8 pad0[0x32];
    s16 yaw;
} ActorYaw;

extern f32 Actor_WorldDistXYZToActor(ActorYaw *, ActorYaw *);
extern s16 Actor_WorldYawTowardActor(ActorYaw *, ActorYaw *);

s32 func_800BBF38(ActorYaw *a0, ActorYaw *a1, f32 a2, f32 a3) {
    s16 d;
    s32 absd;

    if (a3 > 0.0f && Actor_WorldDistXYZToActor(a1, a0) < a3 * 2.5f + a2) {
        d = Actor_WorldYawTowardActor(a1, a0) - a1->yaw;
        if (d < 0) {
            absd = -d;
        } else {
            absd = d;
        }
        if (absd < 0x1400) {
            return 1;
        }
    }
    return 0;
}

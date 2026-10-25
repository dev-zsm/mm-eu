#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    Vec3f pos;
    s16 unkC;
} StickInit;

extern void EffectSs_Spawn(void *play, s32 a1, s32 a2, StickInit *init);

void EffectSsStick_Spawn(void *play, Vec3f *pos, s16 yaw) {
    StickInit init;

    init.pos = *pos;
    init.unkC = yaw;
    EffectSs_Spawn(play, 0x10, 0x80, &init);
}

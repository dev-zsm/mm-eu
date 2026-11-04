#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

extern void EffectSs_Spawn(void *play, s32 type, s32 priority, void *params);

void EffectSsStone1_Spawn(void *play, Vec3f *pos, s32 reg0) {
    struct {
        Vec3f pos;
        s32 reg0;
    } params;

    params.pos = *pos;
    params.reg0 = reg0;
    EffectSs_Spawn(play, 0x14, 0x80, &params);
}

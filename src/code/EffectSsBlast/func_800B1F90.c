#include "types.h"
#include "generated/code_funcs.h"

extern u8 D_801AF280[];
extern u8 D_801AF284[];
extern void EffectSsBlast_Spawn();

void EffectSsBlast_SpawnWhiteCustomScale(struct PlayState *play, struct Vec3f *pos, struct Vec3f *velocity, struct Vec3f *accel, s16 scale, s16 scaleStep, s16 life) {
    EffectSsBlast_Spawn(play, pos, velocity, accel, D_801AF280, D_801AF284, scale, scaleStep, 0x23, life);
}

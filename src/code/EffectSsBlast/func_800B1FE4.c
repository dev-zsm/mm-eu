#include "types.h"
#include "generated/code_funcs.h"

extern void EffectSsBlast_Spawn(void *arg0, void *arg1, void *arg2, void *arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s16 arg9);

void EffectSsBlast_SpawnShockwave(struct PlayState *play, struct Vec3f *pos, struct Vec3f *velocity, struct Vec3f *accel, struct Color_RGBA8 *primColor, struct Color_RGBA8 *envColor, s16 life) {
    EffectSsBlast_Spawn(play, pos, velocity, accel, primColor, envColor, 100, 0x177, 0x23, life);
}

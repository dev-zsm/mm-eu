#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    void *actor;
    Vec3f pos;
    s16 scale;
    s16 params;
    s16 flags;
    s16 bodyPart;
} EffectSsEnFireInitParams;

void Math_Vec3f_Copy(Vec3f *dst, Vec3f *src);
void Actor_PlaySfx(void *actor, s32 sfxId);
void EffectSs_Spawn(void *play, s32 type, s32 priority, void *initParams);

void EffectSsEnFire_SpawnVec3f(void *play, void *actor, Vec3f *pos, s16 scale, s16 params, s16 flags, s16 bodyPart) {
    EffectSsEnFireInitParams initParams;

    Math_Vec3f_Copy(&initParams.pos, pos);
    initParams.actor = actor;
    initParams.scale = scale;
    initParams.params = params;
    initParams.flags = flags;
    initParams.bodyPart = bodyPart;
    if (actor != NULL) {
        Actor_PlaySfx(actor, 0x2822);
    }
    EffectSs_Spawn(play, 0x1D, 0x80, &initParams);
}

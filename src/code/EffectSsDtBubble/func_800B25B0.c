#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    u8 r, g, b, a;
} Color_RGBA8;

typedef struct {
    Vec3f pos;
    Vec3f velocity;
    Vec3f accel;
    Color_RGBA8 primColor;
    Color_RGBA8 envColor;
    s16 scale;
    s16 life;
    s16 colorProfile;
    s16 randXZ;
    u8 customColor;
} EffectSsDtBubbleInitParams;

void Math_Vec3f_Copy(Vec3f *dst, Vec3f *src);
void EffectSs_Spawn(void *play, s32 type, s32 priority, void *initParams);

void EffectSsDtBubble_SpawnColorProfile(void *play, Vec3f *pos, Vec3f *velocity, Vec3f *accel, s16 scale, s16 life,
                                        s16 colorProfile, s16 randXZ) {
    EffectSsDtBubbleInitParams initParams;

    Math_Vec3f_Copy(&initParams.pos, pos);
    Math_Vec3f_Copy(&initParams.velocity, velocity);
    Math_Vec3f_Copy(&initParams.accel, accel);
    initParams.customColor = 0;
    initParams.colorProfile = colorProfile;
    initParams.scale = scale;
    initParams.life = life;
    initParams.randXZ = randXZ;
    EffectSs_Spawn(play, 0xE, 0x80, &initParams);
}

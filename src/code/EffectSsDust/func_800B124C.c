#include "types.h"

typedef struct { f32 x, y, z; } Vec3f;
typedef struct { u8 r, g, b, a; } Color_RGBA8;
typedef struct {
    Vec3f pos;
    Vec3f velocity;
    Vec3f accel;
    Color_RGBA8 primColor;
    Color_RGBA8 envColor;
    s16 scale;
    s16 scaleStep;
    s16 life;
    u16 type;
    u8 drawFlags;
} DustInit;

void Math_Vec3f_Copy(Vec3f *dst, Vec3f *src);
void EffectSs_Spawn(s32 play, s32 type, s32 priority, DustInit *init);

void EffectSsDust_Spawn(s32 play, u16 type, Vec3f *pos, Vec3f *velocity, Vec3f *accel, Color_RGBA8 *primColor,
                        Color_RGBA8 *envColor, s16 scale, s16 scaleStep, s16 life, u8 drawFlags) {
    DustInit init;

    Math_Vec3f_Copy(&init.pos, pos);
    Math_Vec3f_Copy(&init.velocity, velocity);
    Math_Vec3f_Copy(&init.accel, accel);
    init.primColor = *primColor;
    init.envColor = *envColor;
    init.type = type;
    init.scale = scale;
    init.scaleStep = scaleStep;
    init.life = life;
    init.drawFlags = drawFlags;
    EffectSs_Spawn(play, 0, 0x80, &init);
}

#include "types.h"
#include "code_funcs.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    Vec3f pos;
    Vec3f velocity;
    Vec3f accel;
    s16 scale;
    s16 scaleStep;
} ExtraInitParams;

extern void Math_Vec3f_Copy(Vec3f *dst, void *src);

void EffectSsExtra_Spawn(void *play, void *pos, void *velocity, void *accel, s16 scale, s16 scaleStep) {
    ExtraInitParams params;

    Math_Vec3f_Copy(&params.pos, pos);
    Math_Vec3f_Copy(&params.velocity, velocity);
    Math_Vec3f_Copy(&params.accel, accel);
    params.scale = scale;
    params.scaleStep = scaleStep;
    EffectSs_Spawn(play, 0x1E, 0x64, &params);
}

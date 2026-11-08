#include "types.h"
#include "generated/code_funcs.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    Vec3f pos;
    Vec3f velocity;
    Vec3f accel;
    s16 unk40;
    s16 unk42;
    s16 unk44;
} SibukiInitParams;

extern void Math_Vec3f_Copy(Vec3f *dst, void *src);

void EffectSsSibuki_Spawn(struct PlayState *play, struct Vec3f *pos, struct Vec3f *velocity, struct Vec3f *accel, s16 moveDelay, s16 direction, s16 scale) {
    SibukiInitParams params;

    Math_Vec3f_Copy(&params.pos, pos);
    Math_Vec3f_Copy(&params.velocity, velocity);
    Math_Vec3f_Copy(&params.accel, accel);
    params.unk40 = moveDelay;
    params.unk42 = direction;
    params.unk44 = scale;
    EffectSs_Spawn(play, 0x11, 0x80, &params);
}

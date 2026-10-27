#include "types.h"

typedef struct { f32 x, y, z; } Vec3f;
typedef struct { u8 r, g, b, a; } Color;

typedef struct {
    s32 unk0;
    Vec3f pos;
    Vec3f vel;
    Vec3f accel;
    Color c1;
    Color c2;
    s16 unk48;
    s16 unk4A;
    u8 unk4C;
} Init;

extern void Math_Vec3f_Copy(Vec3f *dst, Vec3f *src);
extern void Color_RGBA8_Copy(Color *dst, Color *src);
extern void EffectSs_Spawn(void *play, s32 a1, s32 a2, Init *init);

void EffectSsGSpk_SpawnAccel(void *play, s32 a1, Vec3f *pos, Vec3f *vel, Vec3f *accel, Color *c1, Color *c2,
                             s16 s1, s16 s2) {
    Init init;

    Math_Vec3f_Copy(&init.pos, pos);
    Math_Vec3f_Copy(&init.vel, vel);
    Math_Vec3f_Copy(&init.accel, accel);
    Color_RGBA8_Copy(&init.c1, c1);
    Color_RGBA8_Copy(&init.c2, c2);
    init.unk0 = a1;
    init.unk48 = s1;
    init.unk4A = s2;
    init.unk4C = 0;
    EffectSs_Spawn(play, 5, 0x80, &init);
}

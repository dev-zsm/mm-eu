#include "types.h"

typedef struct { f32 x, y, z; } Vec3f;
typedef struct {
    Vec3f pos;
    Vec3f velocity;
    Vec3f accel;
    s16 gravity;
    s16 scale;
    s16 unk40;
    s16 unk42;
    s16 unk44;
    s16 unk46;
    s16 unk48;
    s16 unk4A;
    s32 unk4C;
    s16 unk50;
    s16 unk52;
    s32 unk54;
} KakeraInit;

void Math_Vec3f_Copy(Vec3f *dst, Vec3f *src);
void EffectSs_Spawn(s32 play, s32 type, s32 priority, KakeraInit *init);

void EffectSsKakera_Spawn(s32 play, Vec3f *pos, Vec3f *velocity, Vec3f *accel, s16 a4, s16 a5, s16 a6, s16 a7,
                          s16 a8, s16 a9, s16 a10, s16 a11, s32 a12, s16 a13, s16 a14, s32 a15) {
    KakeraInit init;

    Math_Vec3f_Copy(&init.pos, pos);
    Math_Vec3f_Copy(&init.velocity, velocity);
    Math_Vec3f_Copy(&init.accel, accel);
    init.gravity = a4;
    init.scale = a5;
    init.unk40 = a6;
    init.unk42 = a7;
    init.unk44 = a8;
    init.unk46 = a9;
    init.unk48 = a10;
    init.unk4A = a11;
    init.unk4C = a12;
    init.unk50 = a13;
    init.unk52 = a14;
    init.unk54 = a15;
    EffectSs_Spawn(play, 0x19, 0x65, &init);
}

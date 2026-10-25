#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    s32 unk0;
    s16 unk4;
    Vec3f pos;
} HitmarkInit;

extern void Math_Vec3f_Copy(Vec3f *dest, Vec3f *src);
extern void EffectSs_Spawn(void *play, s32 type, s32 priority, void *init);

void EffectSsHitmark_Spawn(void *play, s32 arg1, s16 arg2, Vec3f *pos) {
    HitmarkInit init;

    init.unk0 = arg1;
    init.unk4 = arg2;
    Math_Vec3f_Copy(&init.pos, pos);
    EffectSs_Spawn(play, 0x15, 0x80, &init);
}

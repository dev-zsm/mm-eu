#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ Vec3f unkC;
    /* 0x18 */ Vec3f unk18;
    /* 0x24 */ s16 unk24;
    /* 0x26 */ u8 unk26;
    /* 0x28 */ void *unk28;
    /* 0x2C */ u8 unk2C;
} EffectSsFhgFlashInitParams;

void Math_Vec3f_Copy(Vec3f *dest, Vec3f *src);
void EffectSs_Spawn(void *play, s32 type, s32 priority, void *initParams);

void EffectSsFhgFlash_SpawnShock(void *play, void *arg1, Vec3f *pos, s16 arg3, u8 arg4) {
    EffectSsFhgFlashInitParams initParams;

    initParams.unk28 = arg1;
    Math_Vec3f_Copy(&initParams.pos, pos);
    initParams.unk24 = arg3;
    initParams.unk26 = arg4;
    initParams.unk2C = 1;
    EffectSs_Spawn(play, 0x16, 0x80, &initParams);
}

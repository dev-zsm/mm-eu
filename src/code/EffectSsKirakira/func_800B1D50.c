#include "types.h"

typedef struct { f32 x, y, z; } V3;
typedef struct {
    V3 pos;
    V3 vel;
    V3 accel;
    u8 primColor[4];
    u8 envColor[4];
    s16 scaleStep;
    s16 arg6;
    s32 life;
    s16 rotSpeed;
    s16 rand;
    s8 type;
} KirakiraInit;

f32 func_8008704C(void);
void EffectSs_Spawn(s32 play, s32 a, s32 b, void *c);
void Math_Vec3f_Copy(void *a, void *b);
void Color_RGBA8_Copy(void *a, s32 b);

void EffectSsKirakira_SpawnFocused(s32 play, s32 unused, void *pos, void *vel, s32 primColor, s32 envColor, s16 yaw, s32 life) {
    KirakiraInit init;

    Math_Vec3f_Copy(&init.pos, unused);
    Math_Vec3f_Copy(&init.vel, pos);
    Math_Vec3f_Copy(&init.accel, vel);
    init.life = life;
    init.type = 1;
    init.rotSpeed = 0x1518;
    init.rand = func_8008704C() * 16384.0f;
    init.arg6 = yaw;
    Color_RGBA8_Copy(init.primColor, primColor);
    Color_RGBA8_Copy(init.envColor, envColor);
    init.scaleStep = 2.0f * -(255.0f / init.life);
    EffectSs_Spawn(play, 1, 0x80, &init);
}

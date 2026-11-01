#include "types.h"
#include "code_funcs.h"

typedef struct {
    void *actor;
    f32 pos[3];
    f32 scale;
    u8 pad14[0x2C - 0x14];
    u8 primColor[4];
    u8 envColor[4];
    u8 pad34[4];
    s16 unk38;
} InitParams2FE4;

void Math_Vec3f_Copy(f32 *, f32 *);

void EffectSsEnIce_SpawnFlying(void *play, void *actor, f32 *pos, u8 *primColor, u8 *envColor, f32 scale) {
    InitParams2FE4 p;

    p.actor = actor;
    Math_Vec3f_Copy(p.pos, pos);
    Color_RGBA8_Copy(p.primColor, primColor);
    Color_RGBA8_Copy(p.envColor, envColor);
    p.unk38 = 0;
    p.scale = scale;
    if (actor != NULL) {
        Actor_PlaySfx(actor, 0x874);
    }
    EffectSs_Spawn(play, 0x1B, 0x50, &p);
}

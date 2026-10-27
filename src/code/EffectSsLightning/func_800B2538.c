#include "types.h"

typedef struct {
    f32 pos[3];
    u8 primColor[4];
    u8 envColor[4];
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    s16 unk1E;
} InitParams2538;

void Math_Vec3f_Copy(f32 *, f32 *);
void Color_RGBA8_Copy(u8 *, u8 *);
void EffectSs_Spawn(void *, s32, s32, void *);

void EffectSsLightning_Spawn(void *play, f32 *pos, u8 *primColor, u8 *envColor, s16 a, s16 b, s16 c, s16 d) {
    InitParams2538 p;

    Math_Vec3f_Copy(p.pos, pos);
    Color_RGBA8_Copy(p.primColor, primColor);
    Color_RGBA8_Copy(p.envColor, envColor);
    p.unk18 = a;
    p.unk1A = b;
    p.unk1C = c;
    p.unk1E = d;
    EffectSs_Spawn(play, 0xD, 0x80, &p);
}

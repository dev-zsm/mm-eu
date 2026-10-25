#include "types.h"

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Color_RGBA8;

extern Color_RGBA8 D_801AF290;
extern Color_RGBA8 D_801AF294;
extern void EffectSsGSpk_SpawnSmall(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, Color_RGBA8 *a5, Color_RGBA8 *a6);

void EffectSsGSpk_SpawnFuse(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    Color_RGBA8 primColor = D_801AF290;
    Color_RGBA8 envColor = D_801AF294;

    EffectSsGSpk_SpawnSmall(a0, a1, a2, a3, a4, &primColor, &envColor);
}

#include "types.h"

typedef struct {
    u8 r, g, b, a;
} Color4;

extern Color4 D_801AF278;
extern Color4 D_801AF27C;

extern void EffectSsKirakira_SpawnDispersed(void *play, void *pos, void *velocity, void *accel, Color4 *primColor,
                                            Color4 *envColor, s32 scale, s32 life);

void EffectSsKirakira_SpawnSmallYellow(void *play, void *pos, void *velocity, void *accel) {
    Color4 primColor = D_801AF278;
    Color4 envColor = D_801AF27C;

    EffectSsKirakira_SpawnDispersed(play, pos, velocity, accel, &primColor, &envColor, 1000, 16);
}

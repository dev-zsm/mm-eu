#include "types.h"

extern u8 D_801AF288[];
extern u8 D_801AF28C[];

void EffectSsBlast_SpawnShockwave(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 *primColor, u8 *envColor, s32 duration);

void EffectSsBlast_SpawnWhiteShockwave(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    EffectSsBlast_SpawnShockwave(arg0, arg1, arg2, arg3, D_801AF288, D_801AF28C, 10);
}

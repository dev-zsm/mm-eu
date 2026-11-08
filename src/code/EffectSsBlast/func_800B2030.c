#include "types.h"
#include "generated/code_funcs.h"

extern u8 D_801AF288[];
extern u8 D_801AF28C[];


void EffectSsBlast_SpawnWhiteShockwave(struct PlayState *play, struct Vec3f *pos, struct Vec3f *velocity, struct Vec3f *accel) {
    EffectSsBlast_SpawnShockwave(play, pos, velocity, accel, D_801AF288, D_801AF28C, 10);
}

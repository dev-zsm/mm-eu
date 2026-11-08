// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

M2C_UNK EffectSsSibuki_SpawnBurst(s32, s32);                    /* extern */
M2C_UNK CollisionCheck_SpawnWaterDroplets(s32, s32);                    /* extern */

void CollisionCheck_WaterBurst(struct PlayState *play, struct Collider *collider, struct Vec3f *v) {
    EffectSsSibuki_SpawnBurst(play, v);
    CollisionCheck_SpawnWaterDroplets(play, v);
}

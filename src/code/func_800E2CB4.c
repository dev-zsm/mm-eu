// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK EffectSsSibuki_SpawnBurst(s32, s32);                    /* extern */
M2C_UNK CollisionCheck_SpawnWaterDroplets(s32, s32);                    /* extern */

void CollisionCheck_WaterBurst(s32 arg0, M2C_UNK arg1, s32 arg2) {
    EffectSsSibuki_SpawnBurst(arg0, arg2);
    CollisionCheck_SpawnWaterDroplets(arg0, arg2);
}

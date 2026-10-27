// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK CollisionCheck_SpawnShieldParticles();                            /* extern */
M2C_UNK Audio_PlaySfx(M2C_UNK);                     /* extern */

void CollisionCheck_SpawnShieldParticlesMetal(void) {
    CollisionCheck_SpawnShieldParticles();
    Audio_PlaySfx(0x1808);
}

#include "types.h"
#include "code_funcs.h"
void CollisionCheck_SpawnShieldParticlesMetalSound(s32 a0, s32 a1, s32 a2) {
    CollisionCheck_SpawnShieldParticles(a0, a1);
    Audio_PlaySfx_AtPos(a2, 0x1808);
}

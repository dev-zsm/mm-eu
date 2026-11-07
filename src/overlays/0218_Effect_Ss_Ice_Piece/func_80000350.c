// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_ice_piece.h"

void EffectSsIcePiece_Update(PlayState* play, u32 index, EffectSs* this) {
    this->rPitch += this->rRotSpeed;
    this->velocity.x *= 0.85f;
    this->velocity.y *= 0.85f;
    this->velocity.z *= 0.85f;
}

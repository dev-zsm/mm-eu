// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_numa_hana.h"

void BgNumaHana_OpenedIdle(BgNumaHana* this, PlayState* play) {
    this->dyna.actor.shape.rot.y += this->flowerAngularVelocity;
    this->petalRotZ = this->innerPetalRotZ + this->settleRotZ;
    BgNumaHana_UpdatePetalPosRots(this);
    Actor_PlaySfx_Flagged(&this->dyna.actor, NA_SE_EV_FLOWER_ROLLING - SFX_FLAG);
}

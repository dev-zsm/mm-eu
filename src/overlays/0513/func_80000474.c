// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_mirror.h"

void BgIkanaMirror_EmitLight(BgIkanaMirror* this, PlayState* play) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(this->lightRaysColliders); i++) {
        if (this->lightRaysColliders[i].base.atFlags & AT_HIT) {
            this->lightRaysColliders[i].base.atFlags &= ~AT_HIT;
        }
    }

    if (this->lightEmissionAlpha < 155) {
        this->lightEmissionAlpha += 100;
    } else {
        this->lightEmissionAlpha = 255;
    }

    if (this->lightAbsorptionAlpha > 60) {
        this->lightAbsorptionAlpha -= 60;
    } else {
        this->lightAbsorptionAlpha = 0;
    }

    if (this->lightRayCharge > 0) {
        this->lightRayCharge--;

        for (i = 0; i < ARRAY_COUNT(this->lightRaysColliders); i++) {
            CollisionCheck_SetAT(play, &play->colChkCtx, &this->lightRaysColliders[i].base);
        }

    } else {
        this->dyna.actor.flags &= ~ACTOR_FLAG_DRAW_CULLING_DISABLED;
        BgIkanaMirror_SetupWait(this);
    }
}

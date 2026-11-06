// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_block.h"

void ref_func_80B7F398(BgIkanaBlock* this, PlayState* play) {
    if (this->unk_17D > 0) {
        this->unk_17D--;
        return;
    }

    this->dyna.actor.velocity.y -= 2.0f;
    this->dyna.actor.velocity.y *= 0.95f;

    if (this->dyna.actor.velocity.y < -30.0f) {
        this->dyna.actor.velocity.y = -30.0f;
    }

    this->dyna.actor.world.pos.y += this->dyna.actor.velocity.y;

    if (ref_func_80B7EE70(this, play)) {
        Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_BLOCK_BOUND);
        Actor_PlaySfx(&this->dyna.actor,
                      NA_SE_PL_WALK_GROUND + SurfaceType_GetSfxOffset(&play->colCtx, this->dyna.actor.floorPoly,
                                                                      this->dyna.actor.floorBgId));
        ref_func_80B7F0A4(this);
    }
}

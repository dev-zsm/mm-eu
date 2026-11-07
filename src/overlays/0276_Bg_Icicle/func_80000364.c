// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_icicle.h"

void BgIcicle_Shiver(BgIcicle* this, PlayState* play) {
    s32 randSign;
    f32 rand;

    if (this->shiverTimer != 0) {
        this->shiverTimer--;
    }

    if (!(this->shiverTimer % 4)) {
        Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_ICE_SWING);
    }

    if (this->shiverTimer == 0) {
        this->dyna.actor.world.pos.x = this->dyna.actor.home.pos.x;
        this->dyna.actor.world.pos.z = this->dyna.actor.home.pos.z;

        CollisionCheck_SetAT(play, &play->colChkCtx, &this->collider.base);
        DynaPoly_DisableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
        this->actionFunc = BgIcicle_Fall;
    } else {
        rand = Rand_ZeroOne();
        randSign = (Rand_ZeroOne() < 0.5f ? -1 : 1);
        this->dyna.actor.world.pos.x = (randSign * ((0.5f * rand) + 0.5f)) + this->dyna.actor.home.pos.x;
        rand = Rand_ZeroOne();
        randSign = (Rand_ZeroOne() < 0.5f ? -1 : 1);
        this->dyna.actor.world.pos.z = (randSign * ((0.5f * rand) + 0.5f)) + this->dyna.actor.home.pos.z;
    }
}

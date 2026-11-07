// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_icicle.h"

void BgIcicle_Fall(BgIcicle* this, PlayState* play) {
    if ((this->collider.base.atFlags & AT_HIT) || (this->dyna.actor.bgCheckFlags & BGCHECKFLAG_GROUND)) {
        this->collider.base.atFlags &= ~AT_HIT;
        this->dyna.actor.bgCheckFlags &= ~BGCHECKFLAG_GROUND;

        if (this->dyna.actor.world.pos.y < this->dyna.actor.floorHeight) {
            this->dyna.actor.world.pos.y = this->dyna.actor.floorHeight;
        }

        BgIcicle_Break(this, play, 40.0f);

        if (this->dyna.actor.params == ICICLE_STALACTITE_REGROW) {
            this->dyna.actor.world.pos.y = this->dyna.actor.home.pos.y + 120.0f;
            DynaPoly_EnableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
            this->actionFunc = BgIcicle_Regrow;
        } else {
            Actor_Kill(&this->dyna.actor);
        }
    } else {
        Actor_MoveWithGravity(&this->dyna.actor);
        this->dyna.actor.world.pos.y += 40.0f;
        Actor_UpdateBgCheckInfo(play, &this->dyna.actor, 0.0f, 0.0f, 0.0f, UPDBGCHECKINFO_FLAG_4);
        this->dyna.actor.world.pos.y -= 40.0f;
        CollisionCheck_SetAT(play, &play->colChkCtx, &this->collider.base);
    }
}

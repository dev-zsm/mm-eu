// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_spout_fire.h"

void BgSpoutFire_Update(Actor* thisx, PlayState* play) {
    s32 pad;
    BgSpoutFire* this = (BgSpoutFire*)thisx;

    this->flameTexIndex = (this->flameTexIndex + 1) % 8;
    if ((this->collider.base.atFlags & AT_HIT)) {
        this->collider.base.atFlags &= ~AT_HIT;
        ref_func_80A60DA0(this, play);
    }
    this->actionFunc(this, play);
    if (this->actionFunc == ref_func_80A60D10) {
        ref_func_80A60E08(this, play);
        CollisionCheck_SetAT(play, &play->colChkCtx, &this->collider.base);
        CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
        Actor_PlaySfx_Flagged(&this->actor, NA_SE_EV_FIRE_PLATE - SFX_FLAG);
    }
}

// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_kin2_bombwall.h"

void BgKin2Bombwall_Wait(BgKin2Bombwall* this, PlayState* play) {
    if (BgKin2Bombwall_IsHitFromNearby(this, play)) {
        this->collider.base.acFlags &= ~AC_HIT;
        CutsceneManager_Queue(this->dyna.actor.csId);
        BgKin2Bombwall_SetupPlayCutscene(this);
    } else {
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
    }
}

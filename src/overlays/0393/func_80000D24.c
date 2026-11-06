// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_bombwall.h"

void ref_func_80ABCCE4(BgHakuginBombwall* this, PlayState* play) {
    BgHakuginBombwallStruct* ptr = &ref_D_80ABCFC0[BGHAKUGIN_BOMBWALL_100(&this->dyna.actor)];

    if (ptr->unk_20(this, play)) {
        this->dyna.actor.flags |= ACTOR_FLAG_UPDATE_CULLING_DISABLED;
        CutsceneManager_Queue(this->dyna.actor.csId);
        this->actionFunc = ref_func_80ABCD98;
    } else {
        this->collider.base.acFlags &= ~AC_HIT;
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
    }
}

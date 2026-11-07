// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_icicle.h"

void BgIcicle_Update(Actor* thisx, PlayState* play) {
    s32 pad;
    BgIcicle* this = (BgIcicle*)thisx;

    BgIcicle_UpdateAttacked(this, play);
    this->actionFunc(this, play);

    if (this->actionFunc != BgIcicle_Regrow) {
        Collider_UpdateCylinder(&this->dyna.actor, &this->collider);
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
    }
}

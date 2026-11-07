// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_pzlblock.h"

void ref_func_809A3E58(Actor* thisx, PlayState* play) {
    ObjPzlblock* this = (ObjPzlblock*)thisx;

    this->actionFunc(this, play);

    this->dyna.actor.world.pos.y = this->dyna.actor.home.pos.y;

    if (this->updBgCheckInfoFlags != 0) {
        Actor_UpdateBgCheckInfo(play, &this->dyna.actor, 15.0f, 30.0f, 0.0f, this->updBgCheckInfoFlags);
        if (((this->actionFunc == ref_func_809A3A74) || (this->actionFunc == ref_func_809A3D38)) &&
            (this->dyna.actor.bgCheckFlags & BGCHECKFLAG_GROUND) &&
            !DynaPoly_GetActor(&play->colCtx, this->dyna.actor.floorBgId)) {
            this->updBgCheckInfoFlags = 0;
        }
    }
}

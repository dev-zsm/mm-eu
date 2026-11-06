// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

s32 ref_func_80A5BFD8(EnKusa2* this, PlayState* play) {
    if (this->collider.base.acFlags & AC_HIT) {
        s32 pad;

        ref_func_80A5CF44(this);
        ref_func_80A5BD14(this, play, (this->collider.elem.acHitElem->atDmgInfo.dmgFlags & 0x1000000) ? 1 : 0);
        SoundSource_PlaySfxAtFixedWorldPos(play, &this->actor.world.pos, 20, NA_SE_EV_PLANT_BROKEN);
        ref_func_80A5BD94(this);
        Actor_Kill(&this->actor);
        return true;
    }
    return false;
}

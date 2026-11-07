// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_last_bwall.h"

void ref_func_80C187F8(BgLastBwall* this, PlayState* play) {
    if (this->colliderTris.base.acFlags & AC_HIT) {
        this->colliderTris.base.acFlags &= ~AC_HIT;
        Flags_SetSwitch(play, BGLASTBWALL_GET_SWITCH_FLAG(&this->dyna.actor));
        ref_func_80C1886C(this, play);
    } else {
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->colliderTris.base);
    }
}

// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bombf.h"

void ref_func_808AEF68(EnBombf* this, PlayState* play) {
    if (Actor_HasNoParent(&this->actor, play)) {
        EnBombf_SetupAction(this, ref_func_808AEE3C);
        this->actor.bgCheckFlags &= ~BGCHECKFLAG_GROUND;
        ref_func_808AEE3C(this, play);
    } else {
        this->actor.velocity.y = 0.0f;
    }
}

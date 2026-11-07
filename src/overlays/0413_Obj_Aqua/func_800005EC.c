// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_aqua.h"

void ref_func_80ACBC8C(ObjAqua* this, PlayState* play) {
    if (this->actor.bgCheckFlags & (BGCHECKFLAG_GROUND | BGCHECKFLAG_WATER)) {
        if (this->actor.bgCheckFlags & BGCHECKFLAG_GROUND) {
            ref_func_80ACB7F4(this, play);
            ref_func_80ACBA10(this);
            Actor_PlaySfx(&this->actor, NA_SE_EV_BOTTLE_WATERING);
            ref_func_80ACBD34(this);
        } else {
            ref_func_80ACB6A0(this, play);
            SoundSource_PlaySfxAtFixedWorldPos(play, &this->actor.world.pos, 0x28, NA_SE_EV_BOMB_DROP_WATER);
            Actor_Kill(&this->actor);
        }
    } else if (this->counter <= 0) {
        Actor_Kill(&this->actor);
    }
}

// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

void ref_func_80A5DC98(EnKusa2* this, PlayState* play) {
    if (!ref_func_80A5BFD8(this, play)) {
        if (this->actor.velocity.y > 1.0f) {
            Math_StepToF(&this->actor.scale.y, 0.3f, 0.060000002f);
            Math_StepToF(&this->actor.scale.x, 0.328f, 0.040000003f);
        } else {
            Math_StepToF(&this->actor.scale.y, 0.48000002f, 0.080000006f);
            Math_StepToF(&this->actor.scale.x, 0.28f, 0.032f);
        }

        this->actor.scale.z = this->actor.scale.x;
        Math_StepToF(&this->actor.gravity, -7.0f, 1.8f);
        Actor_MoveWithGravity(&this->actor);
        ref_func_80A5BAFC(this, play);
        ref_func_80A5BF38(this, 4);
        ref_func_80A5BF84(this, play);

        if (this->actor.bgCheckFlags & BGCHECKFLAG_GROUND) {
            ref_func_80A5CD0C(this);
            ref_func_80A5BB40(this, play, 1);
            Actor_PlaySfx(&this->actor, NA_SE_EN_NUTS_WALK);
            ref_func_80A5DE18(this);
        } else if (this->actor.bgCheckFlags & BGCHECKFLAG_WATER) {
            ref_func_80A5BDB0(this, play);
            ref_func_80A5E418(this);
        } else if (this->unk_1CA > 0) {
            this->unk_1CA--;
        } else {
            Actor_Kill(&this->actor);
        }
    }
}

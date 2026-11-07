// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_mkk.h"

void ref_func_80A4E67C(EnMkk* this) {
    this->unk_14B |= 1;
    this->actor.flags &= ~ACTOR_FLAG_ATTENTION_ENABLED;
    this->collider.base.acFlags &= ~AC_ON;
    this->actor.flags |= ACTOR_FLAG_UPDATE_CULLING_DISABLED;
    Actor_PlaySfx(&this->actor, NA_SE_EN_PO_DEAD);
    this->alpha = 254;
    ref_func_800BE568(&this->actor, &this->collider);
    this->actor.speed = 7.0f;
    this->actor.shape.rot.y = this->actor.world.rot.y;
    this->actor.velocity.y = 5.0f;
    this->actor.gravity = -1.3f;
    this->actor.bgCheckFlags &= ~BGCHECKFLAG_GROUND;
    this->actionFunc = ref_func_80A4E72C;
}

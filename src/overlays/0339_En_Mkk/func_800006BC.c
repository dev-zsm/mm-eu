// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_mkk.h"

void ref_func_80A4E58C(EnMkk* this) {
    this->unk_14B |= 1;
    this->actor.speed = 3.0f;
    this->actor.velocity.y = 5.0f;
    Actor_PlaySfx(&this->actor, NA_SE_EN_KUROSUKE_ATTACK);
    this->collider.base.atFlags |= AT_ON;
    Math_ScaledStepToS(&this->actor.shape.rot.y, this->actor.yawTowardsPlayer, 0x800);
    this->actionFunc = ref_func_80A4E60C;
}

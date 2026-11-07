// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_mkk.h"

void ref_func_80A4E100(EnMkk* this, PlayState* play) {
    s32 newAlpha;

    if (this->unk_14B & 4) {
        newAlpha = this->alpha + 15;
    } else {
        newAlpha = this->alpha + 5;
    }
    if (newAlpha >= 255) {
        this->primColorSelect = 3;
        this->collider.base.acFlags |= AC_ON;
        this->alpha = 255;
        this->actor.flags |= ACTOR_FLAG_ATTENTION_ENABLED;
        this->actor.shape.rot.y = this->actor.yawTowardsPlayer;
        this->unk_14B &= ~4;
        ref_func_80A4E190(this);
    } else {
        this->alpha = newAlpha;
    }
}

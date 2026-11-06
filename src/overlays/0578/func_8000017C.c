// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_sc_ruppe.h"

void ref_func_80BD6A8C(EnScRuppe* this, PlayState* play) {
    if (this->collider.base.ocFlags1 & OC1_HIT) {
        this->ruppeDisplayTime = 0;
        this->actor.gravity = 0.0f;
        Actor_PlaySfx(&this->actor, NA_SE_SY_GET_RUPY);
        Rupees_ChangeBy(sRupeeInfo[this->ruppeIndex].amount);
        this->actionFunc = ref_func_80BD6B18;
    }
    this->actor.shape.rot.y += 0x1F4;
    Actor_MoveWithGravity(&this->actor);
}

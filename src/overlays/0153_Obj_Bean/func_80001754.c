// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bean.h"

void ref_func_80938444(ObjBean* this, PlayState* play) {
    s32 pad;
    s32 sp20 = Math_StepToF(&this->dyna.actor.scale.y, 0.16672663f, 0.01f) & 1;

    sp20 &= Math_StepToF(&this->dyna.actor.scale.x, 0.03569199f, 0.00113f);

    this->dyna.actor.scale.z = this->dyna.actor.scale.x;
    if (sp20) {
        if (this->unk_1B2 <= 0) {
            ref_func_809384E8(this);
        }
    } else {
        this->unk_1B2 = 1;
    }
    Actor_PlaySfx_Flagged(&this->dyna.actor, NA_SE_PL_PLANT_GROW_UP - SFX_FLAG);
}

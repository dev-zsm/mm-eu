// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bean.h"

void ref_func_80937B54(ObjBean* this) {
    Math_StepToS(&this->unk_1EE, this->unk_1F0, this->unk_1F2);
    Math_StepToS(&this->unk_1F4, this->unk_1F6, this->unk_1F8);
    this->unk_1FA += this->unk_1F4;
    this->unk_1FC = 6372.0f - (Math_SinS(this->unk_1FA) * this->unk_1EE);
    this->dyna.actor.scale.y = Math_SinS(this->unk_1FC) * 0.17434467f;
    this->dyna.actor.scale.x = this->dyna.actor.scale.z = Math_CosS(this->unk_1FC) * 0.12207746f;
}

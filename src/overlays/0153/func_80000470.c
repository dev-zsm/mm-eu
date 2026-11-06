// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bean.h"

void ref_func_80937160(ObjBean* this) {
    this->unk_1AC += 0x384;
    if (this->unk_1AC > 0x5FFF) {
        this->unk_1AC = 0x5FFF;
    }

    this->unk_1AE += 0x258;
    if (this->unk_1AE > 0x4000) {
        this->unk_1AE = 0x4000;
    }

    this->dyna.actor.scale.y = Math_SinS(this->unk_1AC) * 0.16970563f;
    this->dyna.actor.scale.x = this->dyna.actor.scale.z = Math_SinS(this->unk_1AE) * 0.10700001f;
    Math_StepToF(&this->unk_1CC, 0.0f, 0.1f);
    Math_StepToF(&this->unk_1D0, 0.0f, 0.1f);
    Math_ScaledStepToS(&this->dyna.actor.shape.rot.y, this->dyna.actor.home.rot.y, 0x64);
}

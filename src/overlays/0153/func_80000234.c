// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bean.h"

void ref_func_80936F24(ObjBean* this) {
    this->unk_1AC += 0xB6;
    this->unk_1AE += 0xFB;
    this->unk_1B0 += 0x64;
    Math_StepToF(&this->unk_1C8, 2.0f, 0.1f);
    this->unk_1CC = (Math_SinS(this->unk_1AC * 3) + Math_SinS(this->unk_1AE * 3)) * this->unk_1C8;
    this->unk_1D0 = (Math_CosS(this->unk_1AC * 4) + Math_CosS(this->unk_1AE * 4)) * this->unk_1C8;
    this->dyna.actor.scale.z =
        ((Math_SinS(this->unk_1B0 * 5) * 0.06f) + (Math_SinS(this->unk_1AE * 8) * 0.01f) + 1.07f) * 0.1f;
    this->dyna.actor.scale.x = this->dyna.actor.scale.z;
    this->dyna.actor.scale.y = ((Math_CosS(this->unk_1B0 * 10) * 0.2f) + 1.0f) * 0.1f;
    this->dyna.actor.shape.rot.y = (this->dyna.actor.home.rot.y + (s32)(Math_SinS(this->unk_1AC * 3) * 1000.0f)) +
                                   (s32)(Math_SinS(this->unk_1B0 * 2) * 2100.0f);
}

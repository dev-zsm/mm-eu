// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hunsui.h"

void ref_func_80B9D094(ObjHunsui* this, PlayState* play) {
    f32 sins;

    this->unk_18A += 0x71C;
    Math_SmoothStepToF(&this->unk_190, this->unk_194, 1.0f, 0.2f, 0.01f);
    sins = Math_SinS(this->unk_18A);
    this->unk_198 = sins * this->unk_190;
}

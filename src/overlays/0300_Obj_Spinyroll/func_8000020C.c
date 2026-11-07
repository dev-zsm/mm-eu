// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_spinyroll.h"

void ref_func_80A1DC5C(ObjSpinyroll* this) {
    this->unk_4D8 += 0x5DC0;
    Math_StepToF(&this->unk_4D4, 0.0f, 0.32f);
    this->unk_4D0 = ((Math_SinS(this->unk_4D8) + 1.0f) * this->unk_4D4) + 24.0f;
}

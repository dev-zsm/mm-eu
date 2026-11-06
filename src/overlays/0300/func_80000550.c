// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_spinyroll.h"

void ref_func_80A1DFA0(ObjSpinyroll* this) {
    f32 temp_f0;
    f32 phi_f12;
    s32 i;
    s32 j;
    f32 temp_f2;

    this->unk_3A4.unk_F4 = (s32)(ref_D_80A1F1B8[OBJSPINYROLL_GET_C000(&this->dyna.actor)] * 120.0f * (1.0f / 58)) + 2;

    temp_f0 = (ref_D_80A1F1B8[OBJSPINYROLL_GET_C000(&this->dyna.actor)] * 120.0f) - 2.0f;
    temp_f2 = temp_f0 / (this->unk_3A4.unk_F4 - 1);
    temp_f0 *= 0.5f;

    for (i = 0; i < ARRAY_COUNT(this->unk_3A4.unk_00); i++) {
        for (j = 0, phi_f12 = temp_f0; j < this->unk_3A4.unk_F4; j++, phi_f12 -= temp_f2) {
            this->unk_3A4.unk_00[i][j].unk_00 = phi_f12;
        }
    }
}

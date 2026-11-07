// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_driftice.h"

f32 ref_func_80A665EC(ObjDrifticeStruct* arg0, ObjDriftice* this) {
    f32 phi_f2 = 0.0f;
    f32 sp20;

    if (this->unk_248 >= 10) {
        sp20 = -8.0f;
    } else if (this->unk_248 < -9) {
        sp20 = 0.0f;
    } else if (this->unk_248 > 0) {
        sp20 = (Math_CosS(fabsf(this->unk_248) * (0x8000 * 0.1f)) - 1.0f) * 4.0f;
    } else {
        sp20 = (Math_CosS(fabsf(this->unk_248) * (0x8000 * 0.1f)) + 1.0f) * -4.0f;
    }

    if (this->unk_248 > 0) {
        if (arg0->unk_00.unk_00 > 0) {
            arg0->unk_00.unk_00--;
        } else {
            arg0->unk_00.unk_00 = Rand_S16Offset(30, 70);
            arg0->unk_00.unk_04 = Rand_S16Offset(1000, 1000);
            arg0->unk_00.unk_0C = (Rand_ZeroOne() * 1.5f) + 1.0f;
            arg0->unk_00.unk_10 = fabsf(arg0->unk_00.unk_0C - arg0->unk_00.unk_08) * 0.05f;
        }
    } else {
        arg0->unk_00.unk_00 = 0;
        arg0->unk_00.unk_0C = phi_f2;
        arg0->unk_00.unk_10 = (fabsf(arg0->unk_00.unk_0C - arg0->unk_00.unk_08) * 0.05f) + 0.02f;
    }

    arg0->unk_00.unk_02 += arg0->unk_00.unk_04;
    Math_StepToF(&arg0->unk_00.unk_08, arg0->unk_00.unk_0C, arg0->unk_00.unk_10);

    sp20 += (Math_SinS(arg0->unk_00.unk_02) * arg0->unk_00.unk_08);
    return sp20;
}

// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_driftice.h"

f32 ref_func_80A667F0(ObjDrifticeStruct3* arg0, ObjDriftice* this) {
    f32 temp_f20 = 0.0f;
    ObjDrifticeStruct3* temp_s0;
    s32 i;

    for (i = 0; i < 3; i++) {
        temp_s0 = &arg0[i];

        if (temp_s0->unk_00 > 0) {
            temp_s0->unk_00--;
        } else {
            temp_s0->unk_00 = Rand_S16Offset(30, 70);
            temp_s0->unk_04 = Rand_S16Offset(ref_D_80A67694[i].unk_00, ref_D_80A67694[i].unk_02);
            temp_s0->unk_0C = ref_D_80A67694[i].unk_04 + (ref_D_80A67694[i].unk_08 * Rand_ZeroOne());
            temp_s0->unk_10 = fabsf(temp_s0->unk_0C - temp_s0->unk_08) * 0.05f;
        }
        temp_s0->unk_02 += temp_s0->unk_04;
        Math_StepToF(&temp_s0->unk_08, temp_s0->unk_0C, temp_s0->unk_10);
        temp_f20 += Math_SinS(temp_s0->unk_02) * temp_s0->unk_08;
    }

    return temp_f20;
}

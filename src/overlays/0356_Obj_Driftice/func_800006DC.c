// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_driftice.h"

void ref_func_80A66C4C(ObjDrifticeStruct4* arg0, ObjDriftice* this, s16* arg2, s16* arg3) {
    ObjDrifticeStruct3* temp_s0;
    f32 temp_f20 = 0.0f;
    s32 i;

    if (arg0->unk_00[0] > 0) {
        arg0->unk_00[0]--;
    } else {
        arg0->unk_00[0] = Rand_S16Offset(30, 70);
        arg0->unk_00[2] = Rand_S16Offset(-200, 200);
        arg0->unk_00[4] = Rand_S16Offset(-400, 400);
    }

    Math_StepToS(&arg0->unk_00[1], arg0->unk_00[2], 0x32);
    Math_StepToS(&arg0->unk_00[3], arg0->unk_00[4], 0x32);

    *arg3 = arg0->unk_00[3] + arg0->unk_00[1];

    for (i = 0; i < 3; i++) {
        temp_s0 = &arg0->unk_0C[i];

        if (temp_s0->unk_00 > 0) {
            temp_s0->unk_00--;
        } else {
            temp_s0->unk_00 = Rand_S16Offset(30, 70);
            temp_s0->unk_04 = Rand_S16Offset(ref_D_80A676D0[i].unk_00, ref_D_80A676D0[i].unk_02);
            temp_s0->unk_0C = ref_D_80A676D0[i].unk_04 + (ref_D_80A676D0[i].unk_08 * Rand_ZeroOne());
            temp_s0->unk_10 = fabsf(temp_s0->unk_0C - temp_s0->unk_08) * 0.033333335f;
        }
        temp_s0->unk_02 += temp_s0->unk_04;
        Math_StepToF(&temp_s0->unk_08, temp_s0->unk_0C, temp_s0->unk_10);
        temp_f20 += Math_SinS(temp_s0->unk_02) * temp_s0->unk_08;
    }

    *arg2 = temp_f20;
}

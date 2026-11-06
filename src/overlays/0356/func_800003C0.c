// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_driftice.h"

void ref_func_80A66930(ObjDrifticeStruct2* arg0, ObjDriftice* this, s16* arg2, s16* arg3) {
    ObjDrifticeStruct3* temp_s0;
    f32 temp_f22 = 0.0f;
    s16 phi_s0;
    s32 i;

    if (this->unk_248 > 0) {
        f32 temp_f20 = this->dyna.actor.xzDistToPlayer * this->unk_240 * 0.0007075472f;

        if (temp_f20 > 1.0f) {
            temp_f20 = 1.0f;
        } else if (temp_f20 < 0.01f) {
            temp_f20 = 0.01f;
        }

        Math_StepToS(&arg0->unk_02, 1200.0f * temp_f20, 0x64);
        phi_s0 = 2500.0f * temp_f20;
        Math_StepToS(&arg0->unk_06, Math_CosS(arg0->unk_04 * 6.5536f) * (120.0f * temp_f20), 0x28);
        Math_StepToF(&arg0->unk_08, 1.0f, 0.02f);
    } else {
        Math_StepToS(&arg0->unk_02, 0, 0x96);
        phi_s0 = 0;
        Math_StepToS(&arg0->unk_06, 20, 7);
        Math_StepToF(&arg0->unk_08, 0.0f, 0.02f);
    }
    Math_ScaledStepToS(&arg0->unk_00, this->dyna.actor.yawTowardsPlayer, arg0->unk_02);
    *arg3 = arg0->unk_00;
    Math_ScaledStepToS(&arg0->unk_04, phi_s0, arg0->unk_06);

    for (i = 0; i < 2; i++) {
        temp_s0 = &arg0->unk_0C[i];

        if (temp_s0->unk_00 > 0) {
            temp_s0->unk_00--;
        } else {
            temp_s0->unk_00 = Rand_S16Offset(30, 70);
            temp_s0->unk_04 = Rand_S16Offset(ref_D_80A676B8[i].unk_00, ref_D_80A676B8[i].unk_02);
            temp_s0->unk_0C = ref_D_80A676B8[i].unk_04 + (ref_D_80A676B8[i].unk_08 * Rand_ZeroOne());
            temp_s0->unk_10 = fabsf(temp_s0->unk_0C - temp_s0->unk_08) * 0.033333335f;
        }
        temp_s0->unk_02 += temp_s0->unk_04;
        Math_StepToF(&temp_s0->unk_08, temp_s0->unk_0C, temp_s0->unk_10);
        temp_f22 += Math_SinS(temp_s0->unk_02) * temp_s0->unk_08;
    }

    temp_f22 *= arg0->unk_08;

    *arg2 = (s32)temp_f22 + arg0->unk_04;
}

// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_grass.h"

void ObjGrass_CalcAnimationMatrices(ObjGrass* this) {
    s32 i;
    s32 pad;
    f32* ptr;
    f32 temp_f28;
    f32 spA4;
    f32 spA0;
    f32 temp_f22;
    f32 temp_f24;
    f32 sp94;
    f32 sp90;
    f32 temp_f26;
    f32 sp6C[8];
    f32 tempf1;
    f32 tempf2;
    f32 tempf3;
    f32 tempf4;
    f32 tempf5;
    f32 temp_f16;
    f32 temp_f20;

    this->unk_3288 += 70;
    this->unk_328A += 300;
    this->unk_328C += 700;
    this->unk_328E += 1300;
    this->unk_3290 += 8900;

    temp_f24 = Math_SinS(this->unk_3288);
    temp_f28 = Math_SinS(this->unk_328A);
    temp_f26 = Math_SinS(this->unk_328C);
    spA4 = Math_SinS(this->unk_328E) * 1.2f;
    spA0 = Math_SinS(this->unk_3290) * 1.5f;
    temp_f22 = Math_CosS(this->unk_3288);
    temp_f20 = Math_CosS(this->unk_328A);
    sp94 = Math_CosS(this->unk_328C);
    sp90 = Math_CosS(this->unk_328E) * 1.3f;
    temp_f16 = Math_CosS(this->unk_3290) * 1.7f;

    sp6C[0] = (temp_f24 - temp_f20) * temp_f26 * temp_f22 * temp_f24 * 0.0015f;
    sp6C[1] = (temp_f28 - sp94) * spA4 * temp_f20 * temp_f24 * 0.0015f;
    sp6C[2] = (temp_f26 - sp90) * sp94 * temp_f24 * temp_f22 * 0.0015f;
    sp6C[3] = (spA4 - temp_f20) * sp90 * temp_f28 * temp_f22 * 0.0015f;
    sp6C[4] = (temp_f24 - sp94) * temp_f24 * temp_f28 * spA0 * 0.0015f;
    sp6C[5] = (temp_f28 - sp90) * temp_f26 * spA4 * spA0 * 0.0015f;
    sp6C[6] = (temp_f26 - temp_f22) * temp_f22 * temp_f20 * temp_f16 * 0.0015f;
    sp6C[7] = (spA4 - temp_f20) * sp94 * sp90 * temp_f16 * 0.0015f;

    for (i = 0; i < ARRAY_COUNT(this->distortionMtx); i++) {
        ptr = &this->distortionMtx[i].mf[0][0];

        tempf1 = sp6C[(i + 0) & 7];
        tempf2 = sp6C[(i + 1) & 7];
        tempf3 = sp6C[(i + 2) & 7];
        tempf4 = sp6C[(i + 3) & 7];
        tempf5 = sp6C[(i + 4) & 7];

        ptr[0] = sp6C[1] * 0.2f;
        ptr[1] = tempf1;
        ptr[2] = tempf2;
        ptr[3] = 0.0f;

        ptr[4] = tempf3;
        ptr[5] = sp6C[0];
        ptr[6] = tempf3;
        ptr[7] = 0.0f;

        ptr[8] = tempf4;
        ptr[9] = tempf5;
        ptr[10] = sp6C[3] * 0.2f;
        ptr[11] = 0.0f;

        ptr[12] = 0.0f;
        ptr[13] = 0.0f;
        ptr[14] = 0.0f;
        ptr[15] = 0.0f;
    }
}

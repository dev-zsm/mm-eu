// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_flowerpot.h"

void ref_func_80A1B3D0(void) {
    s32 i;
    s32 pad;
    f32 spB4;
    f32* ptr;
    f32 spAC;
    f32 spA8;
    f32 tempf1;
    f32 tempf2;
    f32 tempf3;
    f32 tempf4;
    f32 tempf5;
    f32 sp74[8];
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f26;
    f32 temp_f28;
    f32 temp_f0;
    f32 temp_f30;

    ref_D_80A1DA38 += 70;
    ref_D_80A1DA3A += 300;
    ref_D_80A1DA3C += 700;
    ref_D_80A1DA3E += 1300;
    ref_D_80A1DA40 += 8900;

    temp_f28 = Math_SinS(ref_D_80A1DA38);
    spB4 = Math_SinS(ref_D_80A1DA3A);
    temp_f30 = Math_SinS(ref_D_80A1DA3C);
    spAC = Math_SinS(ref_D_80A1DA3E);
    spA8 = Math_SinS(ref_D_80A1DA40);
    temp_f26 = Math_CosS(ref_D_80A1DA38);
    temp_f20 = Math_CosS(ref_D_80A1DA3A);
    temp_f22 = Math_CosS(ref_D_80A1DA3C);
    temp_f24 = Math_CosS(ref_D_80A1DA3E);
    temp_f0 = Math_CosS(ref_D_80A1DA40);

    sp74[0] = (temp_f28 - temp_f20) * temp_f30 * temp_f26 * temp_f28 * 0.0012f;
    sp74[1] = (spB4 - temp_f22) * spAC * temp_f20 * temp_f28 * 0.0012f;
    sp74[2] = (temp_f30 - temp_f24) * temp_f22 * temp_f28 * temp_f26 * 0.0012f;
    sp74[3] = (spAC - temp_f20) * temp_f24 * spB4 * temp_f26 * 0.0012f;
    sp74[4] = (temp_f28 - temp_f22) * temp_f28 * spB4 * spA8 * 0.0013f;
    sp74[5] = (spB4 - temp_f24) * temp_f30 * spAC * spA8 * 0.0013f;
    sp74[6] = (temp_f30 - temp_f26) * temp_f26 * temp_f20 * temp_f0 * 0.0013f;
    sp74[7] = (spAC - temp_f20) * temp_f22 * temp_f24 * temp_f0 * 0.0013f;

    for (i = 0; i < ARRAY_COUNT(ref_D_80A1D838); i++) {
        ptr = &ref_D_80A1D838[i].xx;

        tempf1 = sp74[(i + 0) & 7];
        tempf2 = sp74[(i + 1) & 7];
        tempf3 = sp74[(i + 2) & 7];
        tempf4 = sp74[(i + 3) & 7];
        tempf5 = sp74[(i + 4) & 7];

        ptr[0] = sp74[1] * 0.2f;
        ptr[1] = tempf1;
        ptr[2] = tempf2;
        ptr[3] = 0.0f;

        ptr[4] = tempf3;
        ptr[5] = sp74[0];
        ptr[6] = tempf3;
        ptr[7] = 0.0f;

        ptr[8] = tempf4;
        ptr[9] = tempf5;
        ptr[10] = sp74[3] * 0.2f;
        ptr[11] = 0.0f;

        ptr[12] = 0.0f;
        ptr[13] = 0.0f;
        ptr[14] = 0.0f;
        ptr[15] = 0.0f;
    }
}

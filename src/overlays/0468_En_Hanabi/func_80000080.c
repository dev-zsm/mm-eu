// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_hanabi.h"

s32 ref_func_80B22C80(Vec3f* arg0, EnHanabiStruct* arg1, f32 arg2) {
    Vec3s* phi_s1 = &ref_D_80B23AA0[0];
    f32 temp_f22 = (Rand_ZeroFloat(0.2f) + 0.6f) * arg2;
    s32 temp_s6 = (s32)Rand_ZeroFloat(6.0f) * 3;
    s32 i;
    s32 j;

    for (i = 0, j = 0; j < ARRAY_COUNT(ref_D_80B23AA0) && i < 400; i++, arg1++) {
        if (arg1->unk_00 <= 0) {
            arg1->unk_00 = 1;
            Math_Vec3f_Copy(&arg1->unk_08, arg0);
            arg1->unk_20.x = phi_s1->x * temp_f22;
            arg1->unk_20.y = (phi_s1->y * temp_f22) + 50.0f;
            arg1->unk_20.z = phi_s1->z * temp_f22;
            arg1->unk_04 = 1.5f * arg2;
            ref_func_80B22C2C(arg1, temp_s6);
            phi_s1++;
            j++;
        }
    }

    return temp_s6;
}

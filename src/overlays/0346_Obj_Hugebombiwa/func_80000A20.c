// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hugebombiwa.h"

void ref_func_80A54600(PlayState* play, Vec3f* arg1, f32 arg2, f32 arg3) {
    static f32 ref_D_80A55D60[] = { 3.0f, 5.0f, 9.0f, 18.0f };
    static s8 ref_D_80A55D70 = 0;
    Vec3f spCC;
    Vec3f spC0;
    s32 i;
    f32 spA0;
    s16 temp_s0;
    s16 temp_s1;
    s32 phi_v0;
    s16 phi_v1;
    f32 temp;

    for (i = 0; i < 2; i++) {
        spCC.x = (Rand_ZeroOne() - 0.5f) * 11.0f;
        spCC.y = (Rand_ZeroOne() - 0.2f) * 8.0f;
        spCC.z = (Rand_ZeroOne() - 0.5f) * 11.0f;

        spC0.x = ((Rand_ZeroOne() - 0.5f) * 5.0f) + (spCC.x * 1.4f);
        spC0.y = (Rand_ZeroOne() * 13.0f) + 8.2f + (arg2 * -0.38f);
        spC0.z = ((Rand_ZeroOne() - 0.5f) * 5.0f) + (spCC.z * 1.4f);

        spCC.x += arg1->x;
        spCC.y += arg1->y;
        spCC.z += arg1->z;

        temp = ref_D_80A55D60[ref_D_80A55D70] * arg3;
        phi_v1 = (ref_D_80A55D70 * -90) - 350;
        ref_D_80A55D70++;
        ref_D_80A55D70 &= 3;

        if (temp <= 1.0f) {
            phi_v0 = 1;
        } else {
            phi_v0 = temp;
        }

        EffectSsKakera_Spawn(play, &spCC, &spC0, &spCC, phi_v1, 33, 15, 0, 0, phi_v0, 1, 0, 70, -1, OBJECT_BOMBIWA,
                             object_bombiwa_DL_0009E0);

        spCC.x += (Rand_ZeroOne() - 0.5f) * 270.0f;
        spCC.y += (Rand_ZeroOne() - 0.1f) * 150.0f;
        spCC.z += (Rand_ZeroOne() - 0.5f) * 270.0f;

        temp_s0 = (Rand_ZeroOne() * 160.0f) + 140.0f;
        temp_s1 = (Rand_ZeroOne() * 180.0f) + 120.0f;
        ref_func_800B1210(play, &spCC, &gZeroVec3f, &ref_D_80A55D2C, temp_s0, temp_s1);
    }
}

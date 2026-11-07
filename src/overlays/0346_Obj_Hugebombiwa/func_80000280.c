// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hugebombiwa.h"

void ref_func_80A53E60(PlayState* play, Vec3f* arg1, f32 arg2, f32 arg3) {
    static Color_RGBA8 ref_D_80A55D38 = { 210, 210, 210, 255 };
    static Color_RGBA8 ref_D_80A55D3C = { 140, 140, 140, 255 };
    static f32 ref_D_80A55D40[] = { 3.0f, 5.0f, 9.0f, 18.0f };
    Vec3f spDC;
    Vec3f spD0;
    s32 i;
    f32 temp_f0;
    s32 phi_s1;
    s32 phi_s2;
    s32 phi_v0;
    s32 phi_v1;
    s16 phi_s0;
    s32 pad;

    for (phi_s2 = -300, i = 0; phi_s2 > -540; phi_s2 -= 60, i++) {
        spDC.x = (Rand_ZeroOne() - 0.5f) * 11.0f;
        spDC.y = (Rand_ZeroOne() - 0.2f) * 8.0f;
        spDC.z = (Rand_ZeroOne() - 0.5f) * 11.0f;

        spD0.x = ((Rand_ZeroOne() - 0.5f) * 5.0f) + (spDC.x * 1.4f);
        spD0.y = (Rand_ZeroOne() * 13.0f) + 8.2f + (arg2 * -0.26f);
        if (1) {}
        spD0.z = ((Rand_ZeroOne() - 0.5f) * 5.0f) + (spDC.z * 1.4f);

        spDC.x += arg1->x;
        spDC.y += arg1->y;
        spDC.z += arg1->z;

        if ((s32)(phi_s2 & 0xFFFFFFFF) == -480) {
            phi_v0 = 33;
            phi_s0 = 70;
        } else {
            phi_v0 = 65;
            if (phi_s2 == -420) {
                phi_s0 = 70;
            } else {
                phi_s0 = 40;
                if (Rand_ZeroOne() < 0.7f) {
                    phi_v0 = 64;
                } else {
                    phi_v0 = 32;
                }
            }
        }

        temp_f0 = ref_D_80A55D40[i] * arg3;
        if (temp_f0 <= 1.0f) {
            phi_v1 = 1;
        } else {
            phi_v1 = temp_f0;
        }

        EffectSsKakera_Spawn(play, &spDC, &spD0, &spDC, phi_s2, phi_v0, 15, 0, 0, phi_v1, 1, 0, phi_s0, -1,
                             OBJECT_BOMBIWA, object_bombiwa_DL_001990);

        spDC.x += (Rand_ZeroOne() - 0.5f) * 270.0f;
        spDC.y += (Rand_ZeroOne() - 0.1f) * 150.0f;
        spDC.z += (Rand_ZeroOne() - 0.5f) * 270.0f;

        phi_s0 = (Rand_ZeroOne() * 160.0f) + 140.0f;
        phi_s1 = (Rand_ZeroOne() * 180.0f) + 120.0f;
        ref_func_800B0E48(play, &spDC, &gZeroVec3f, &ref_D_80A55D2C, &ref_D_80A55D38, &ref_D_80A55D3C, phi_s0, phi_s1);
    }
}

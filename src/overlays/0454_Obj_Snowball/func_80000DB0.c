// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_snowball.h"

void ref_func_80B03A80(PlayState* play, f32 arg1, Vec3f* arg2) {
    f32 temp_f30 = sqrtf(arg1);
    Vec3f spD8;
    Vec3f spCC;
    s32 i;
    Gfx* temp_s1;
    f32 temp_f20;
    s16 phi_s2;
    s16 phi_s0;
    s16 phi_s3;
    s32 phi_s5;
    s32 tmp;
    s32 pad;

    for (i = 0, phi_s5 = 0; i < 13; i++, phi_s5 += 0x1999) {
        tmp = i & 3;

        temp_f20 = (Rand_ZeroOne() * (40.0f * arg1)) + 20.0f;

        spD8.x = Math_SinS((s32)(Rand_ZeroOne() * 6553.6f) + phi_s5) * temp_f20;
        spD8.y = Rand_ZeroOne() * temp_f20;
        spD8.z = Math_CosS((s32)(Rand_ZeroOne() * 6553.6f) + phi_s5) * temp_f20;

        spCC.x = spD8.x * 0.17f;
        spCC.y = (Rand_ZeroOne() * 14.0f) + 3.0f;
        spCC.z = spD8.z * 0.17f;

        spD8.x += arg2->x;
        spD8.y += arg2->y;
        spD8.z += arg2->z;

        if (tmp == 0) {
            temp_s1 = ref_D_80B04FC8[0];
            phi_s2 = -400;
            phi_s3 = 1;
            if ((s32)Rand_Next() > 0) {
                phi_s0 = 0x21;
            } else {
                phi_s0 = 0x41;
            }
        } else if (tmp == 1) {
            temp_s1 = ref_D_80B04FC8[1];
            phi_s2 = -340;
            phi_s3 = 1;
            if ((s32)Rand_Next() > 0) {
                phi_s0 = 0x21;
            } else {
                phi_s0 = 0x41;
            }
        } else {
            temp_s1 = ref_D_80B04FC8[2];
            phi_s2 = -280;
            phi_s3 = 0;
            phi_s0 = 0x40;
        }

        EffectSsKakera_Spawn(play, &spD8, &spCC, &spD8, phi_s2, phi_s0, 30, 0, 0,
                             ((Rand_ZeroOne() * 15.0f) + 25.0f) * arg1, phi_s3, 0, 0x36, -1, OBJECT_GOROIWA, temp_s1);

        spD8.x += (Rand_ZeroOne() * 80.0f) - 40.0f;
        spD8.y += Rand_ZeroOne() * 55.0f;
        spD8.z += (Rand_ZeroOne() * 80.0f) - 40.0f;

        phi_s0 = (s32)(Rand_ZeroOne() * 60.0f * temp_f30) + 60;

        ref_func_800B0E48(play, &spD8, &gZeroVec3f, &ref_D_80B04FBC, &ref_D_80B04FB4, &ref_D_80B04FB8, phi_s0,
                      (s32)(Rand_ZeroOne() * 30.0f * temp_f30) + 60);
    }
}

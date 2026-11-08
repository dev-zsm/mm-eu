// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

void ref_func_80940A1C(PlayState* play, Vec3f* arg1, Gfx** arg2, Color_RGBA8* arg3, Color_RGBA8* arg4, f32 arg5) {
    s32 i;
    Vec3f spE8;
    Vec3f spDC;
    s32 phi_s2;
    s32 phi_s0;
    s32 phi_s3;
    Gfx* phi_s1;
    s32 spC8;
    f32 temp_f20;
    f32 spAC;
    s16 spA8;
    s16 phi_s6;

    spC8 = (s32)(arg5 * 35.0f) + 5;
    temp_f20 = (arg5 + 0.1f) * 0.5f;
    spAC = 600.0f * temp_f20;
    spA8 = 0x10000 / spC8;

    for (i = 0, phi_s6 = 0; i < spC8; i++, phi_s6 += spA8) {
        temp_f20 = (Rand_ZeroOne() * arg5 * 400.0f) + 20.0f;

        spE8.x = Math_SinS((s32)(Rand_ZeroOne() * spA8) + phi_s6) * temp_f20;
        spE8.y = (Rand_ZeroOne() - 0.2f) * temp_f20 * 0.8f;
        spE8.z = Math_CosS((s32)(Rand_ZeroOne() * spA8) + phi_s6) * temp_f20;

        spDC.x = spE8.x * 0.17f;
        spDC.y = (Rand_ZeroOne() * 14.0f) + 3.0f;
        spDC.z = spE8.z * 0.17f;

        Math_Vec3f_Sum(&spE8, arg1, &spE8);

        if ((i & 3) == 0) {
            phi_s1 = arg2[2];
            phi_s2 = -0x118;
            phi_s3 = 0;
            phi_s0 = 0x40;
        } else {
            phi_s3 = 1;
            if ((i & 3) == 1) {
                phi_s1 = arg2[1];
                phi_s2 = -0x154;
                if ((s32)Rand_Next() > 0) {
                    phi_s0 = 0x21;
                } else {
                    phi_s0 = 0x41;
                }
            } else {
                phi_s1 = arg2[0];
                phi_s2 = -0x190;
                if ((s32)Rand_Next() > 0) {
                    phi_s0 = 0x21;
                } else {
                    phi_s0 = 0x41;
                }
            }
        }

        EffectSsKakera_Spawn(play, &spE8, &spDC, &spE8, phi_s2, phi_s0, 30, 0, 0,
                             ((Rand_ZeroOne() * 150.0f) + 250.0f) * arg5, phi_s3, 0, 0x36, -1, OBJECT_GOROIWA, phi_s1);

        spE8.x += ((Rand_ZeroOne() * 800.0f) - 400.0f) * arg5;
        spE8.y += ((Rand_ZeroOne() * 800.0f) - 250.0f) * arg5;
        spE8.z += ((Rand_ZeroOne() * 800.0f) - 400.0f) * arg5;

        ref_func_800B0E48(play, &spE8, &ref_D_80942E48, &ref_D_80942E54, arg3, arg4, (Rand_ZeroOne() * 60.0f) + spAC,
                      (Rand_ZeroOne() * 30.0f) + spAC);
    }
}

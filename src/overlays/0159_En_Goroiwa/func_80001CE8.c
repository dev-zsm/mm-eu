// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

void ref_func_80940588(PlayState* play, Vec3f* arg1, Gfx* arg2[], Color_RGBA8* arg3, Color_RGBA8* arg4, f32 arg5) {
    Gfx* phi_s7;
    Vec3f sp100;
    Vec3f spF4;
    Vec3f spE8;
    f32 temp_f20;
    f32 spB0;
    s32 j;
    s32 i;
    s32 phi_s0;
    s32 spD0;
    s16 spCE;
    s16 spA8;
    s16 phi_fp;
    s16 spC8;
    f32 spAC;

    spD0 = (s32)(arg5 * 35.0f) + 6;
    temp_f20 = (arg5 + 0.1f) * 0.5f;
    spB0 = 550.0f * temp_f20;
    spAC = 500.0f * temp_f20;
    spA8 = 0x10000 / spD0;

    for (i = 0, spCE = 0; i < spD0; i++, spCE += spA8) {
        temp_f20 = (Rand_ZeroOne() * arg5 * 500.0f) + 20.0f;

        sp100.x = Math_SinS((s32)(Rand_ZeroOne() * spA8) + spCE) * temp_f20;
        sp100.y = (Rand_ZeroOne() - 0.4f) * temp_f20 * 1.6666666f;
        sp100.z = Math_CosS((s32)(Rand_ZeroOne() * spA8) + spCE) * temp_f20;

        spF4.x = sp100.x * 0.19f;
        spF4.y = (Rand_ZeroOne() * 16.0f) + 3.0f;
        spF4.z = sp100.z * 0.19f;

        Math_Vec3f_Sum(&sp100, arg1, &sp100);

        if ((i & 3) == 0) {
            phi_s7 = arg2[0];
            phi_fp = -0x190;
            spC8 = 1;
            if ((s32)Rand_Next() > 0) {
                phi_s0 = 0x21;
            } else {
                phi_s0 = 0x41;
            }
        } else {
            spC8 = 0;
            if ((i & 3) == 1) {
                phi_fp = -0x154;
                phi_s7 = arg2[1];
                if (Rand_ZeroOne() < 0.4f) {
                    phi_s0 = 0x20;
                } else {
                    phi_s0 = 0x40;
                }
            } else {
                phi_fp = -0x118;
                phi_s0 = 0x40;
                phi_s7 = arg2[2];
            }
        }

        EffectSsKakera_Spawn(play, &sp100, &spF4, &sp100, phi_fp, phi_s0, 30, 0, 0,
                             ((Rand_ZeroOne() * 100.0f) + 170.0f) * arg5, spC8, 0, 0x36, -1, OBJECT_GOROIWA, phi_s7);

        for (j = 0; j < 2; j++) {
            spE8.x = (((Rand_ZeroOne() * 1000.0f) - 500.0f) * arg5) + sp100.x;
            spE8.y = (((Rand_ZeroOne() * 1300.0f) - 500.0f) * arg5) + sp100.y;
            spE8.z = (((Rand_ZeroOne() * 1000.0f) - 500.0f) * arg5) + sp100.z;
            ref_func_800B0E48(play, &spE8, &ref_D_80942E48, &ref_D_80942E54, arg3, arg4, (Rand_ZeroOne() * 80.0f) + spB0,
                          (Rand_ZeroOne() * 70.0f) + spAC);
        }
    }
}

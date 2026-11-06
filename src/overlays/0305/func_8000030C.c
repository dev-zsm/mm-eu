// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

void ref_func_80A2339C(PlayState* play, Vec3f* arg1, f32 arg2, f32 arg3, s32 arg4) {
    Vec3f spBC;
    Vec3f spB0;
    Vec3f spA4;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    s32 i;
    f32 sp88;
    s16 temp_s4;
    s16 phi_s0;
    s16 temp;

    spA4.z = 0.0f;
    spA4.x = 0.0f;
    temp_f24 = ((Rand_ZeroOne() * 0.1656f) + 0.3312f) * arg3;
    sp88 = 10.0f * arg3;

    for (i = 0, phi_s0 = 0; i < arg4; i++, phi_s0 += temp) {
        temp = 0x10000 / arg4;

        temp_f20 = ((Rand_ZeroOne() * 0.4f) + 0.6f) * (arg2 * 3.5f);
        temp_s4 = temp_f20 * 100.0f;
        temp_f22 = ((Rand_ZeroOne() * 0.7f) + 0.3f) * arg2 * 300.0f;

        spBC.x = Math_SinS(Rand_S16Offset(phi_s0, temp)) * temp_f22;
        spBC.y = (Rand_ZeroOne() - 0.5f) * (600.0f * arg2);
        spBC.z = Math_CosS(Rand_S16Offset(phi_s0, temp)) * temp_f22;

        spB0.x = spBC.x * temp_f24;
        spB0.y = ((Rand_ZeroOne() * 1.2f) + 0.3f + (temp_f20 * 4.0f)) * sp88;
        spB0.z = spBC.z * temp_f24;

        spBC.x += arg1->x;
        spBC.y += arg1->y;
        spBC.z += arg1->z;

        spA4.y = -0.8f - (temp_f20 * 18.0f);

        EffectSsIceBlock_Spawn(play, &spBC, &spB0, &spA4, temp_s4);
    }
}

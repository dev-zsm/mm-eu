// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

void ref_func_8093EF54(PlayState* play, Vec3f* arg1, Color_RGBA8* arg2, Color_RGBA8* arg3, f32 arg4) {
    Vec3f spC4;
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f24;
    f32 temp_f26;
    s32 temp_f16;
    s16 phi_s0;
    s16 temp;
    f32 temp_f28;
    f32 temp_f30;
    s32 i;

    temp_f0 = (arg4 + 0.1f) * 0.5f;
    temp_f16 = temp_f0 * 165.0f;
    temp_f24 = 470.0f * arg4;
    temp_f30 = 400.0f * arg4;
    temp_f26 = 800.0f * temp_f0;
    temp_f28 = 600.0f * temp_f0;
    temp = 0x10000 / temp_f16;

    for (i = 0, phi_s0 = 0; i < temp_f16; i++, phi_s0 += temp) {
        
        temp_f20 = Rand_ZeroOne(); spC4.x = (Math_SinS(phi_s0) * (temp_f24 * ((temp_f20 * 0.5f) + 0.5f))) + arg1->x;
        spC4.y = ((Rand_ZeroOne() - 0.5f) * temp_f30) + arg1->y;
        temp_f20 = Rand_ZeroOne(); spC4.z = (Math_CosS(phi_s0) * (temp_f24 * ((temp_f20 * 0.5f) + 0.5f))) + arg1->z;
        

        ref_func_800B0E48(play, &spC4, &ref_D_80942E48, &ref_D_80942E54, arg2, arg3, (Rand_ZeroOne() * temp_f28) + temp_f26,
                      temp_f26);
    }
}

// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

void ref_func_8093F198(PlayState* play, Vec3f* arg1, f32 arg2) {
    Vec3f sp74;
    f32 temp_f20;
    s32 temp_f16;
    s16 temp_lo;
    s16 phi_s0;
    s32 i;

    temp_f16 = (arg2 + 0.1f) * 58.0f;
    sp74.y = arg1->y;
    temp_f20 = 550.0f * arg2;
    temp_lo = 0x10000 / temp_f16;

    for (i = 0, phi_s0 = 0; i < temp_f16; i++, phi_s0 += temp_lo) {
        sp74.x = arg1->x + (Math_SinS((s32)(Rand_ZeroOne() * temp_lo) + phi_s0) * temp_f20);
        sp74.z = arg1->z + (Math_CosS((s32)(Rand_ZeroOne() * temp_lo) + phi_s0) * temp_f20);
        EffectSsGSplash_Spawn(play, &sp74, NULL, NULL, 0, 0x15E);
    }

    EffectSsGRipple_Spawn(play, arg1, 0x1F4, 0x384, 4);
}

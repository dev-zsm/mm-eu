// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_waterfall.h"

void ref_func_80B84348(BgDblueWaterfall* this, PlayState* play, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7,
                   s32 arg8) {
    static s16 ref_D_80B853A4 = 0;
    s32 pad;
    f32 spB8 = 1.0f / arg8;
    s32 i;
    f32 spB0 = this->actor.world.pos.y + arg3;
    s32 pad2;
    f32 temp_f22;
    f32 temp_f24;
    Vec3f sp98;
    Vec3f sp8C;
    Vec3f sp80;
    f32 temp_f26;
    f32 temp_f20;

    for (i = 0; i < arg8; i++) {
        ref_D_80B853A4 += 0x4E20;

        temp_f20 = Math_SinS(ref_D_80B853A4);
        temp_f24 = (Rand_ZeroOne() * (arg2 - arg3)) + (spB8 * i);
        temp_f22 = Math_CosS(ref_D_80B853A4);
        temp_f26 = ((Rand_ZeroOne() * 0.8f) + 0.2f) * arg4;

        sp8C.x = temp_f20 * temp_f26;
        sp8C.y = (Rand_ZeroOne() * 4.0f) + arg5;
        sp8C.z = temp_f22 * temp_f26;

        sp80.x = sp8C.x * -0.016f;
        sp80.y = sp8C.y * -0.015f;
        sp80.z = sp8C.z * -0.016f;

        sp98.x = (temp_f20 * 50.0f) + this->actor.world.pos.x;
        sp98.y = temp_f24 + spB0;
        sp98.z = (temp_f22 * 50.0f) + this->actor.world.pos.z;

        EffectSsIceSmoke_Spawn(play, &sp98, &sp8C, &sp80, (Rand_ZeroOne() * arg7) + arg6);
    }
}

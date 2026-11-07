// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_snowball2.h"

void ref_func_80B39638(PlayState* play, Vec3f* arg1) {
    static s16 ref_D_80B3A938 = 0;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    Vec3f sp98;
    Vec3f sp8C;
    Vec3f sp80;
    f32 temp_f2;
    s32 i;

    ref_D_80B3A938 += (s16)(Rand_Next() >> 0x11);

    for (i = 0; i < 2; i++) {
        ref_D_80B3A938 += 0x8000;
        temp_f20 = Rand_ZeroOne();
        temp_f22 = Math_SinS(ref_D_80B3A938) * temp_f20;
        temp_f24 = Rand_ZeroOne();
        temp_f2 = Math_CosS(ref_D_80B3A938) * temp_f20;

        sp98.x = arg1->x + (temp_f22 * 5.0f);
        sp98.y = arg1->y + (temp_f24 * 25.0f);
        sp98.z = arg1->z + (temp_f2 * 5.0f);

        sp8C.x = temp_f22 * 1.55f;
        sp8C.y = temp_f24 * -0.7f;
        sp8C.z = temp_f2 * 1.55f;

        sp80.x = sp8C.x * -0.02f;
        sp80.y = sp8C.y * -0.025f;
        sp80.z = sp8C.z * -0.02f;

        EffectSsIceSmoke_Spawn(play, &sp98, &sp8C, &sp80, (s32)(Rand_ZeroOne() * 30.0f) + 68);
    }
}

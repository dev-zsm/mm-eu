// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_balance.h"

void ref_func_80B8296C(PlayState* play, Vec3f* arg1, f32 arg2) {
    s32 i;
    Vec3f sp60;
    f32 temp_f0;
    f32 temp_f20 = arg2 * 2;

    for (i = 0; i < ARRAY_COUNT(ref_D_80B83A90); i++) {
        sp60.x = ((Rand_ZeroOne() - 0.5f) * temp_f20) + arg1->x;
        sp60.y = arg1->y;
        sp60.z = ((Rand_ZeroOne() - 0.5f) * temp_f20) + arg1->z;
        EffectSsGRipple_Spawn(play, &sp60, 500, 2000, ref_D_80B83A90[i]);
    }

    for (i = 0; i < ARRAY_COUNT(ref_D_80B83A94); i++) {
        temp_f0 = Rand_ZeroOne();
        temp_f20 = 1.0f - SQ(temp_f0);
        if ((s32)Rand_Next() > 0) {
            temp_f20 = -temp_f20;
        }

        sp60.x = (temp_f20 * arg2) + arg1->x;
        sp60.y = arg1->y;

        temp_f0 = Rand_ZeroOne();
        temp_f20 = 1.0f - SQ(temp_f0);
        if ((s32)Rand_Next() > 0) {
            temp_f20 = -temp_f20;
        }
        sp60.z = (temp_f20 * arg2) + arg1->z;

        EffectSsGRipple_Spawn(play, &sp60, 400, 800, ref_D_80B83A94[i]);
    }
}

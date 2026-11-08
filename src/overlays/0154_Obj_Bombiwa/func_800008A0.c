// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bombiwa.h"

void ref_func_80939C50(PlayState* play, Vec3f* arg1) {
    Vec3f spBC;
    Vec3f spB0;
    s32 phi_v0;
    s32 phi_s0;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(ref_D_8093A9E0); i++) {
        spBC.x = (Rand_ZeroOne() - 0.5f) * 15.0f;
        spBC.y = (Rand_ZeroOne() - 0.2f) * 10.0f;
        spBC.z = (Rand_ZeroOne() - 0.5f) * 15.0f;

        spB0.x = ((Rand_ZeroOne() - 0.5f) * 3.0f) + (spBC.x * 0.85f);
        spB0.y = (Rand_ZeroOne() * 15.0f) + 8.0f;
        spB0.z = ((Rand_ZeroOne() - 0.5f) * 3.0f) + (spBC.z * 0.85f);

        spBC.x += arg1->x;
        spBC.y += arg1->y;
        spBC.z += arg1->z;

        if (i == 0) {
            phi_v0 = 33;
            phi_s0 = 60;
        } else if (i == 1) {
            phi_v0 = 65;
            phi_s0 = 60;
        } else {
            phi_s0 = 40;
            if (Rand_ZeroOne() < 0.7f) {
                phi_v0 = 64;
            } else {
                phi_v0 = 32;
            }
        }
        EffectSsKakera_Spawn(play, &spBC, &spB0, &spBC, -450, phi_v0, 15, 0, 0, ref_D_8093A9E0[i], 1, 0, phi_s0, -1,
                             OBJECT_BOMBIWA, object_bombiwa_DL_005990);
    }

    ref_func_800BBFB0(play, arg1, 60.0f, 4, 80, 140, 1);
}

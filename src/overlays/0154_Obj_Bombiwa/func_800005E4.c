// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bombiwa.h"

void ref_func_80939994(PlayState* play, Vec3f* arg1) {
    Vec3f spAC;
    Vec3f spA0;
    s16 phi_v0;
    s16 life;
    s32 i;

    for (i = 0; i < 16; i++) {
        spAC.x = (Rand_ZeroOne() - 0.5f) * 80.0f;
        spAC.y = Rand_ZeroOne() * 120.0f;
        spAC.z = (Rand_ZeroOne() - 0.5f) * 80.0f;

        spA0.x = ((Rand_ZeroOne() - 0.5f) * 3.0f) + (spAC.x * 0.2f);
        spA0.y = (Rand_ZeroOne() * 16.0f) + 5.0f;
        spA0.z = ((Rand_ZeroOne() - 0.5f) * 3.0f) + (spAC.z * 0.2f);

        spAC.x += arg1->x;
        spAC.y += arg1->y;
        spAC.z += arg1->z;

        if (i >= 14) {
            phi_v0 = 33;
            life = 60;
        } else if (i >= 12) {
            phi_v0 = 65;
            life = 60;
        } else {
            life = 40;
            if (Rand_ZeroOne() < 0.7f) {
                phi_v0 = 64;
            } else {
                phi_v0 = 32;
            }
        }
        EffectSsKakera_Spawn(play, &spAC, &spA0, &spAC, -450, phi_v0, 15, 0, 0, i, 1, 0, life, -1, OBJECT_BOMBIWA,
                             object_bombiwa_DL_005990);
    }

    ref_func_800BBFB0(play, arg1, 120.0f, 3, 80, 140, 1);

    spAC.x = arg1->x;
    spAC.y = arg1->y + 70.0f;
    spAC.z = arg1->z;

    ref_func_800BBFB0(play, &spAC, 120.0f, 3, 80, 140, 1);
}

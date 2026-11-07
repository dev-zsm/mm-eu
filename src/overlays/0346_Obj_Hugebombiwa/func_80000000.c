// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hugebombiwa.h"

void ref_func_80A53BE0(PlayState* play, Vec3f* arg1) {
    Vec3f spBC;
    Vec3f spB0;
    s32 i;
    s32 gravity;
    s16 phi_v0;
    s16 life;
    s16 phi_v1;

    for (i = 0, gravity = -300; i < 16; i++, gravity -= 30) {
        spBC.x = (Rand_ZeroOne() - 0.5f) * 260.0f;
        spBC.y = i * (40.0f / 3);
        spBC.z = (Rand_ZeroOne() - 0.5f) * 260.0f;

        spB0.x = ((Rand_ZeroOne() - 0.5f) * 5.7f) + (spBC.x * 0.035f);
        spB0.y = (Rand_ZeroOne() * 16.0f) + 5.0f + ((16 - i) * 0.25f);
        spB0.z = ((Rand_ZeroOne() - 0.5f) * 5.7f) + (spBC.z * 0.035f);

        spBC.x += arg1->x;
        spBC.y += arg1->y;
        spBC.z += arg1->z;

        if (i >= 14) {
            phi_v0 = 37;
            life = 70;
        } else {
            phi_v0 = 65;
            if (i >= 12) {
                life = 70;
            } else {
                life = 40;
                if (Rand_ZeroOne() < 0.7f) {
                    phi_v0 = 64;
                } else {
                    phi_v0 = 32;
                }
            }
        }

        phi_v1 = i;
        if (phi_v1 <= 0) {
            phi_v1 = 1;
            if (1) {}
        }

        EffectSsKakera_Spawn(play, &spBC, &spB0, &spBC, gravity, phi_v0, 15, 0, 0, phi_v1, 1, 0, life, -1,
                             OBJECT_BOMBIWA, object_bombiwa_DL_001990);
    }
}

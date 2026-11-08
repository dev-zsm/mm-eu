// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bombiwa.h"

void ref_func_80939794(ObjBombiwa* this, PlayState* play) {
    Vec3f spB4;
    Vec3f spA8;
    s32 phi_v1;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(ref_D_8093A9D0); i++) {
        spB4.x = ((Rand_ZeroOne() - 0.5f) * 10.0f) + this->actor.home.pos.x;
        spB4.y = (Rand_ZeroOne() * 5.0f) + this->actor.home.pos.y + 8.0f;
        spB4.z = ((Rand_ZeroOne() - 0.5f) * 10.0f) + this->actor.home.pos.z;

        spA8.x = (Rand_ZeroOne() - 0.5f) * 15.0f;
        spA8.y = (Rand_ZeroOne() * 16.0f) + 5.0f;
        spA8.z = (Rand_ZeroOne() - 0.5f) * 15.0f;

        if (ref_D_8093A9D0[i] > 10) {
            phi_v1 = 0x25;
        } else {
            phi_v1 = 0x21;
        }
        EffectSsKakera_Spawn(play, &spB4, &spA8, &spB4, -400, phi_v1, 10, 2, 0, ref_D_8093A9D0[i], 1, 0, 60, -1,
                             OBJECT_BOMBIWA, object_bombiwa_DL_0009E0);
    }

    ref_func_800BBFB0(play, &this->actor.world.pos, 60.0f, 8, 80, 140, 1);
}

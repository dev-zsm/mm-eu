// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_bombwall.h"

void ref_func_80ABC2E0(BgHakuginBombwall* this, PlayState* play) {
    s32 pad;
    s32 i;
    s16 phi_s2;
    s16 phi_v0;
    s16 phi_v1;
    s16 phi_t0;
    s16 temp_s1;
    Vec3f spC8;
    Vec3f spBC;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;

    for (i = 0, phi_s2 = 0; i < 25; i++, phi_s2 += 0x4E20) {
        temp_f20 = (25 - i) * 2.4f;
        temp_f22 = Math_SinS(phi_s2) * temp_f20;
        temp_f24 = Math_CosS(phi_s2) * temp_f20;

        spC8.x = this->dyna.actor.world.pos.x + temp_f22;
        spC8.y = this->dyna.actor.world.pos.y;
        spC8.z = this->dyna.actor.world.pos.z + temp_f24;

        spBC.x = ((Rand_ZeroOne() - 0.5f) * 10.0f) + (temp_f22 * 0.13333334f);
        spBC.y = (Rand_ZeroOne() * 17.0f) + 7.0f;
        spBC.z = ((Rand_ZeroOne() - 0.5f) * 10.0f) + (temp_f24 * 0.13333334f);

        temp_s1 = (Rand_Next() % 4) + (i >> 2) + 4;

        if ((Rand_Next() % 4) == 0) {
            phi_v0 = 32;
        } else {
            phi_v0 = 64;
        }

        if (temp_s1 >= 8) {
            phi_v0 |= 1;
            phi_v1 = 1;
            phi_t0 = -550;
        } else {
            phi_v1 = 0;
            phi_t0 = -400;
        }

        EffectSsKakera_Spawn(play, &spC8, &spBC, &spC8, phi_t0, phi_v0, 30, 0, 0, temp_s1, phi_v1, 0, 50, -1,
                             OBJECT_HAKUGIN_OBJ, object_hakugin_obj_DL_009830);

        if ((i & 1) == 0) {
            ref_func_800B0E48(play, &spC8, &ref_D_80ABD034, &ref_D_80ABCFB4, &ref_D_80ABCFAC, &ref_D_80ABCFB0, (Rand_Next() >> 0x1B) + 60,
                          (Rand_Next() >> 0x1A) + 50);
        }
    }
}

// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_bombwall.h"

void ref_func_80ABBFC0(BgHakuginBombwall* this, PlayState* play) {
    f32 temp;
    Vec3f spF0;
    Vec3f spE4;
    Vec3f spD8;
    Vec3f spCC;
    s32 pad;
    s16 phi_s1;
    s16 phi_s0;
    s32 i;
    s32 j;

    Matrix_RotateYS(this->dyna.actor.shape.rot.y, MTXMODE_NEW);

    for (i = 0; i < 6; i++) {
        temp = (i + 1) * (80.0f / 3.0f);
        for (j = 0; j < ARRAY_COUNT(ref_D_80ABD020); j++) {
            spD8.x = ref_D_80ABD020[j] + (s32)(Rand_Next() >> 0x1C);
            spD8.y = ((Rand_ZeroOne() - 0.5f) * 15.0f) + temp;
            spD8.z = (Rand_ZeroOne() * 20.0f) - 10.0f;

            spCC.x = ((Rand_ZeroOne() - 0.5f) * 7.0f) + (spD8.x * (7.0f / 90.0f));
            spCC.y = (Rand_ZeroOne() * 7.0f) - 2.0f;
            spCC.z = spD8.z * 0.3f;

            Matrix_MultVec3f(&spD8, &spF0);
            Matrix_MultVec3f(&spCC, &spE4);

            spF0.x += this->dyna.actor.world.pos.x;
            spF0.y += this->dyna.actor.world.pos.y;
            spF0.z += this->dyna.actor.world.pos.z;

            if ((Rand_Next() % 4) == 0) {
                phi_s0 = 32;
            } else {
                phi_s0 = 64;
            }

            if ((s32)Rand_Next() > 0) {
                phi_s0 |= 1;
                phi_s1 = 1;
                ref_func_800B0E48(play, &spF0, &gZeroVec3f, &ref_D_80ABCFB4, &ref_D_80ABCFAC, &ref_D_80ABCFB0,
                              (Rand_Next() >> 0x1B) + 70, (Rand_Next() >> 0x1A) + 60);
            } else {
                phi_s1 = 0;
            }

            EffectSsKakera_Spawn(play, &spF0, &spE4, &spF0, -550, phi_s0, 30, 0, 0, (s32)(Rand_ZeroOne() * 22.0f) + 5,
                                 phi_s1, 0, 50, -1, OBJECT_HAKUGIN_OBJ, object_hakugin_obj_DL_009830);
        }
    }
}

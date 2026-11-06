// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_bombwall.h"

void ref_func_80ABC58C(BgHakuginBombwall* this, PlayState* play) {
    s32 pad;
    Vec3f spD8;
    Vec3f spCC;
    Vec3f spC0;
    Vec3f spB4;
    Vec3f spA8;
    Vec3f sp9C;
    s32 i;
    s16 phi_s1;
    f32 temp_f20;
    f32 temp_f22;

    spA8.y = 0.0f;
    spB4.y = 0.3f;

    Matrix_RotateYS(this->dyna.actor.shape.rot.y, MTXMODE_NEW);

    for (i = 0, phi_s1 = 0; i < 21; i++, phi_s1 += 0x618) {
        temp_f20 = Math_SinS(phi_s1);
        temp_f22 = Math_CosS(phi_s1);

        sp9C.x = (i - 10) * 9.0f;
        sp9C.y = (Rand_ZeroOne() * 40.0f) + 15.0f;
        sp9C.z = temp_f20 * 10.0f;

        spA8.x = ((Rand_ZeroOne() - 0.5f) * 7.0f) + (temp_f22 * -12.0f);
        spA8.z = ((Rand_ZeroOne() - 0.5f) * 7.0f) + (temp_f20 * 16.0f);

        spB4.x = spA8.x * -0.09f;
        spB4.z = spA8.z * -0.09f;

        Matrix_MultVec3f(&sp9C, &spC0);
        Matrix_MultVec3f(&spA8, &spCC);
        Matrix_MultVec3f(&spB4, &spD8);

        spC0.x += this->dyna.actor.world.pos.x;
        spC0.y += this->dyna.actor.world.pos.y;
        spC0.z += this->dyna.actor.world.pos.z;

        ref_func_800B0E48(play, &spC0, &spCC, &spD8, &ref_D_80ABCFAC, &ref_D_80ABCFB0, (Rand_Next() >> 0x1A) + 60,
                      (Rand_Next() >> 0x1B) + 60);
    }
}

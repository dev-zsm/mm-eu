// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_bombwall.h"

void ref_func_80ABC7FC(BgHakuginBombwall* this, PlayState* play) {
    s32 pad;
    Vec3f spB8;
    Vec3f spAC;
    Vec3f spA0;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    s16 phi_s0;
    s32 i;

    spAC.y = 0.0f;
    spB8.y = 0.3f;

    for (i = 0, phi_s0 = 0; i < 20; i++, phi_s0 += 0xCCC) {
        temp_f20 = Math_SinS(phi_s0);
        temp_f22 = Math_CosS(phi_s0);
        temp_f24 = Rand_ZeroOne() * 60.0f;

        spA0.x = (temp_f22 * temp_f24) + this->dyna.actor.world.pos.x;
        spA0.y = (Rand_ZeroOne() * 20.0f) + this->dyna.actor.world.pos.y;
        spA0.z = (temp_f20 * temp_f24) + this->dyna.actor.world.pos.z;

        spAC.x = ((Rand_ZeroOne() - 0.5f) * 7.0f) + (temp_f20 * 15.0f);
        spAC.z = ((Rand_ZeroOne() - 0.5f) * 7.0f) + (temp_f22 * 15.0f);

        spB8.x = spAC.x * -0.095f;
        spB8.z = spAC.z * -0.095f;

        ref_func_800B0E48(play, &spA0, &spAC, &spB8, &ref_D_80ABCFAC, &ref_D_80ABCFB0, (Rand_Next() >> 0x1A) + 60,
                      (Rand_Next() >> 0x1B) + 60);
    }
}

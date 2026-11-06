// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

void ref_func_80941060(EnGoroiwa* this, PlayState* play) {
    Vec3f spAC;
    Vec3f spA0;
    Vec3f sp94;
    Vec3s* vec = &this->collider.elements[0].base.acDmgInfo.hitPos;
    s32 i;

    for (i = 0; i < 4; i++) {
        sp94.x = ((Rand_ZeroOne() * 14.0f) - 7.0f) + vec->x;
        sp94.y = ((Rand_ZeroOne() * 14.0f) - 7.0f) + vec->y;
        sp94.z = ((Rand_ZeroOne() * 14.0f) - 7.0f) + vec->z;

        spA0.x = (Rand_ZeroOne() - 0.5f) * 1.6f;
        spA0.y = -0.8f;
        spA0.z = (Rand_ZeroOne() - 0.5f) * 1.6f;

        spAC.x = spA0.x * -0.06f;
        spAC.y = spA0.y * -0.06f;
        spAC.z = spA0.z * -0.06f;

        ref_func_800B0E48(play, &sp94, &spA0, &spAC, &ref_D_80942E38, &ref_D_80942E44, (s32)(Rand_ZeroOne() * 30.0f) + 15,
                      (s32)(Rand_ZeroOne() * 40.0f) + 30);
    }
}

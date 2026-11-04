// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test7.h"

void EnTest7_UpdateFeatherType2(PlayState* play, OwlWarpFeather* feather) {
    feather->rot.y += feather->angularVelocity.y;

    feather->accel.x = Rand_Centered();
    feather->accel.y = Rand_Centered() + -0.01f;
    feather->accel.z = Rand_Centered();

    feather->velocity.x += feather->accel.x;
    feather->velocity.y += feather->accel.y;
    feather->velocity.z += feather->accel.z;

    feather->pos.x += feather->velocity.x;
    feather->pos.y += feather->velocity.y;
    feather->pos.z += feather->velocity.z;
}

// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_grass_carry.h"

void ObjGrassCarry_RandScaleVecToZero(Vec3f* velocity, f32 scale) {
    scale += ((Rand_ZeroOne() * 0.2f) - 0.1f) * scale;

    velocity->x -= velocity->x * scale;
    velocity->y -= velocity->y * scale;
    velocity->z -= velocity->z * scale;
}

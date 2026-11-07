// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bubble.h"

void EnBubble_Vec3fNormalizedReflect(Vec3f* vec1, Vec3f* vec2, Vec3f* dest) {
    f32 norm;

    Math3D_Vec3fReflect(vec1, vec2, dest);
    norm = sqrtf(SQ(dest->x) + SQ(dest->y) + SQ(dest->z));
    if (norm != 0.0f) {
        dest->x /= norm;
        dest->y /= norm;
        dest->z /= norm;
    } else {
        dest->x = dest->y = dest->z = 0.0f;
    }
}

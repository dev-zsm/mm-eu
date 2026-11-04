// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

s16 CollisionPoly_GetMinY(CollisionPoly* poly, Vec3s* vertices) {
    s16 minY;
    s32 a = COLPOLY_VTX_INDEX(poly->flags_vIA);
    s32 b = COLPOLY_VTX_INDEX(poly->flags_vIB);
    s32 c = poly->vIC;

    minY = vertices[a].y;
    if (vertices[b].y < minY) {
        minY = vertices[b].y;
    }
    if (minY < vertices[c].y) {
        return minY;
    }
    return vertices[c].y;
}

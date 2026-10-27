// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    u8 pad0[0x40];
    Vec3f quad[4]; /* 0x40 */
} ColliderQuad;

// the parenthesized sum order exists only to match the ROM operand order
void CollisionCheck_QuadAvgPoint(ColliderQuad *quad, Vec3f *avg) {
    avg->x = (quad->quad[0].x + (quad->quad[1].x + (quad->quad[3].x + quad->quad[2].x))) * 0.25f;
    avg->y = (quad->quad[0].y + (quad->quad[1].y + (quad->quad[3].y + quad->quad[2].y))) * 0.25f;
    avg->z = (quad->quad[0].z + (quad->quad[1].z + (quad->quad[3].z + quad->quad[2].z))) * 0.25f;
}

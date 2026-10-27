#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct {
    /* 0x00 */ u8 pad0[0x28];
    /* 0x28 */ Vec3f vtx[3];
} ColliderTrisElement;

void CollisionCheck_TrisAvgPoint(ColliderTrisElement *elem, Vec3f *avg) {
    avg->x = (elem->vtx[0].x + elem->vtx[1].x + elem->vtx[2].x) * (1.0f / 3.0f);
    avg->y = (elem->vtx[0].y + elem->vtx[1].y + elem->vtx[2].y) * (1.0f / 3.0f);
    avg->z = (elem->vtx[0].z + elem->vtx[1].z + elem->vtx[2].z) * (1.0f / 3.0f);
}

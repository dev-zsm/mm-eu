#include "types.h"
typedef struct { f32 x, y, z; } Vec3f;
typedef struct { Vec3f p[4]; s16 m1[3]; s16 m2[3]; } Quad;
void Collider_SetQuadMidpoints(Quad *q) {
    q->m1[0] = (q->p[3].x + q->p[2].x) * 0.5f;
    q->m1[1] = (q->p[3].y + q->p[2].y) * 0.5f;
    q->m1[2] = (q->p[3].z + q->p[2].z) * 0.5f;
    q->m2[0] = (q->p[1].x + q->p[0].x) * 0.5f;
    q->m2[1] = (q->p[1].y + q->p[0].y) * 0.5f;
    q->m2[2] = (q->p[1].z + q->p[0].z) * 0.5f;
}

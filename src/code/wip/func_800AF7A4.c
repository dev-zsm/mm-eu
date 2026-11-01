#include "types.h"

typedef struct { s16 x, y, z, pad6, u, v; u8 r, g, b, a; } Vtx_t;
typedef struct { s16 pad0, p0[3], q0[3]; } In;

void EffectTireMark_SetVertices(Vtx_t *vtx, In *in, s32 i, s32 alpha) {
    s32 k = i * 2;
    Vtx_t *v = &vtx[k];

    v->x = in->p0[0];
    v->y = in->p0[1];
    v->u = 0x800;
    v->v = 0;
    v->r = 255;
    v->g = 255;
    v->b = 255;
    v->a = alpha;
    v->z = in->p0[2];
    v[1].x = in->q0[0];
    v[1].y = in->q0[1];
    v[1].z = in->q0[2];
    v = &vtx[k] + 1;
    v->u = 0x800;
    v->v = 0x400;
    v->r = 255;
    v->g = 255;
    v->b = 255;
    v->a = alpha;
}

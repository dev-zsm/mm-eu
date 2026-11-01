#include "types.h"
typedef struct { u8 p0[0x24]; f32 x, y, z; } P;
typedef struct { u8 p0[0x24]; f32 x, y, z; u8 p1[0xC4-0x30]; f32 f; u8 p2[0x21C-0xC8]; s32 a, b; u8 p3[0x22C-0x224]; void *fn; } A;
typedef struct { u8 p0[0x1CCC]; P *pl; } G;
extern u8 D_80AB1E94[];
void func_80000D40(A *a, G *g) {
    P *p = g->pl;
    a->x = p->x;
    a->y = *(f32 *)((u8 *)p + 0xBF0);
    a->z = p->z;
    a->fn = D_80AB1E94;
    a->a = 0;
    a->b = 0;
    a->f = 0.0f;
}

#include "types.h"
typedef struct { u8 p0[0x16]; s16 s; u8 p1[0x230-0x18]; void *f; u8 p2[0x23C-0x234]; s16 t; u8 p3[2]; f32 g; } A;
extern u8 D_808AFBE8[];
void func_80000814(A *x) { s16 v = x->s; x->f = D_808AFBE8; x->g = 0.0f; x->t = v; }

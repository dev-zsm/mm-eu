#include "types.h"
extern u8 D_80B4B7F4[];
extern f32 D_80B4BA00;
typedef struct { u8 pad[0x144]; void *a; f32 b; u8 pad2[8]; s16 c; } A;
void func_80000080(A *s) { s->b = D_80B4BA00; s->a = D_80B4B7F4; s->c = 0; }

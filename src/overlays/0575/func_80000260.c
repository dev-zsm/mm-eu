#include "types.h"
typedef struct { u8 p0[0x68]; f32 f; u8 p1[0x15C-0x6C]; void *fn; } A;
extern u8 D_80BBA6B0[]; extern f32 D_80BBAAC0;
void func_80000260(A *a) { a->f = D_80BBAAC0; a->fn = D_80BBA6B0; }

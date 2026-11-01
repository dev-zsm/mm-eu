#include "types.h"
typedef struct { u8 pad[0x1D4]; void *f; u8 pad2[0x314-0x1D8]; s16 a, b; } A;
extern u8 D_80BB46FC[];
void func_8000076C(A *x) { x->b = 0x63; x->a = 0; x->f = D_80BB46FC; }

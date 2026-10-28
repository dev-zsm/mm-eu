#include "types.h"
typedef struct { u8 pad[0x34]; s32 a, b, c, d, e; } A;
void func_80000BB4(A *x, s32 y) { x->a = 0; x->b = 0; x->c = 0; x->d = 0; x->e = 0; }

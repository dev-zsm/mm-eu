#include "types.h"
typedef struct { u8 pad[0x1D6]; s16 a, b, c; } A;
void func_80000510(A *s) { s16 t = s->b; s->c = -s->c; s->a = t; s->b = t + s->c; }

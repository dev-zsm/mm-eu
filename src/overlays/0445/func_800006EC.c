#include "types.h"
typedef struct { u8 pad[0x1D0]; void *p; } A;
void func_800BDD44(void*, s32, void*, void*);
void func_800006EC(A *a, void *b) { A *s = a; void **g = &b; if (s->p != 0) { func_800BDD44(*g, s->p, s->p, s); } }

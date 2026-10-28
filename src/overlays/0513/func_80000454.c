#include "types.h"
typedef struct { u8 pad[4]; u32 fl; u8 pad2[0x5B8-8]; void *f; } A;
extern u8 D_80B648C4[];
void func_80000454(A *x) { x->fl |= 0x20; x->f = D_80B648C4; }

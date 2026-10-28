#include "types.h"
typedef struct { u8 pad[0x68]; f32 a; u8 pad2[0x160-0x6C]; void *f; } A;
extern u8 D_80BEF948[];
void func_80000448(A *x) { x->f = D_80BEF948; x->a = -10.0f; }

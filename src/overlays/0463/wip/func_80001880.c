#include "types.h"
extern u8 D_80AFD0D4[]; typedef struct { u8 pad[0x280]; u8 *a; u8 *b; } A;
void func_80001880(A *s) { u8 *t = s->a; if (t != D_80AFD0D4) { s->b = t; } s->a = D_80AFD0D4; }

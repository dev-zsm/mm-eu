#include "types.h"
typedef struct { s16 x[3]; } V;
typedef struct { u8 pad[0x30]; V a; u8 pad2[0x86]; V b; } A;
void func_80001628(A *s, s32 a1) { s->b = s->a; }

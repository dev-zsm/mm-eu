#include "types.h"
typedef struct { u8 pad[0xC]; s32 a; s32 b; } A;
extern void func_808672FC();
void func_80000414(A *s, s32 a1) { s->a = 0; s->b = 0; func_808672FC(s, a1, s); }

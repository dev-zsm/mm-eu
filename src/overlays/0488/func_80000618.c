#include "types.h"
typedef struct { u8 pad[0x116]; u16 v; } T;
void func_80000618(u8 *a, u16 b) { T *p = *(T **)(a + 0x2A0); if (p != 0) { p->v = b; } }

#include "types.h"
extern u8 D_809476BC[];
typedef struct { u8 pad[0x160]; s16 v; } Q;
typedef struct { u8 pad0[0x1D4]; void *f; u8 pad1[0xFC]; Q *q; u8 pad2[0x272]; s16 h; } A;
void func_800014C8(A *s) { Q *q = s->q; s->h = 0; q->v = 1; s->f = D_809476BC; }

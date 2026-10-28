#include "types.h"
extern u8 D_80AB472C[];
typedef struct { u8 pad0[0x1F0]; s16 u1F0; } Q;
typedef struct { u8 pad0[0x124]; Q *q; u8 pad128[0x34]; u8 *u15C; } P;
void func_8000025C(P *p) {
    Q *q = p->q;
    q->u1F0 = 0x14;
    p->u15C = D_80AB472C;
}

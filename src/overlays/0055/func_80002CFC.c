#include "types.h"

typedef struct {
    s16 x;
    s16 y;
    u8 pad[12];
} P;

typedef struct {
    u8 pad[0x1A8];
    s16 *p;
} A;

void func_80002CFC(A *a, u16 i, P *tab) {
    P *e = (P *)((u32)tab + i * 16);
    a->p[0] = e->x;
    a->p[1] = e->y;
}

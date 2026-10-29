#include "types.h"
typedef struct { u8 p0[0x3C2]; u8 u3C2, u3C3, u3C4, u3C5; u8 p1[2]; void *u3C8; } A;
extern u8 D_80B15538[];
void func_80000CD0(A *a) {
    a->u3C2 = 0xFF; a->u3C3 = 0xFF; a->u3C4 = 0xFF; a->u3C5 = 0xFF;
    a->u3C8 = D_80B15538;
}

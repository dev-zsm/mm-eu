#include "types.h"

typedef struct { u8 p0[0x2A8]; void *u2A8; u8 p1[0x9C]; s16 u348; } A;
extern void func_80B0D0A0();
extern u8 D_80B0E0F4[];

void func_8000101C(A *a) {
    func_80B0D0A0(a, 5);
    a->u348 = 0;
    a->u2A8 = D_80B0E0F4;
}

#include "types.h"

typedef struct { u8 p0[0x144]; void *u144; } A;
extern void func_80151E7C();
extern u8 D_80A72B3C[];

void func_80001544(s32 a0, A *a1, u16 a2) {
    func_80151E7C(a0, a2 & 0xFFFF);
    a1->u144 = D_80A72B3C;
}

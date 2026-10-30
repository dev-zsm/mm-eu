// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { u8 pad[0x144]; void *p; } S;
extern u8 D_80A72BA0[];
extern void func_80151E7C(s32, u16);

void func_80001580(s32 a0, S *a1, u16 a2) {
    func_80151E7C(a0, a2);
    a1->p = D_80A72BA0;
}

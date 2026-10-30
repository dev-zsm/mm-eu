// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { u8 p0[0x1C4]; void *u1C4; u8 p1[0xC]; s16 u1D4; } A;
extern void func_80A59190();
extern u8 D_80A5927C[];

void func_80000624(A *a) {
    func_80A59190(a, 0);
    a->u1D4 = 0;
    a->u1C4 = D_80A5927C;
}

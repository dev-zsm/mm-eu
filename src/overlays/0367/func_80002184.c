#include "types.h"
extern void func_80A61610();
extern u8 D_80A637D4[];
typedef struct { u8 pad0[0x2A8]; void *fn; u8 pad1[6]; s16 t; u8 pad2[0xC4]; s16 z; } A;
void func_80002184(A *a) {
    func_80A61610(a, 4);
    a->z = 0;
    a->t = 10;
    a->fn = D_80A637D4;
}

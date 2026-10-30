#include "types.h"

typedef struct { u8 pad0[0x188]; void *unk188; u8 pad1[0x31E - 0x18C]; s16 unk31E; } A;
extern void func_80B75928();
extern u8 D_80B73AE8[];

void func_8000086C(A *a0) {
    func_80B75928(a0, 1);
    a0->unk31E = 2;
    a0->unk188 = D_80B73AE8;
}

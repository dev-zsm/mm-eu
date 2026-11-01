#include "types.h"
typedef struct { u8 pad0[0x148]; u8 unk148[0x4654 - 0x148]; void (*unk4654)(); } A;
void func_80B07B3C();
void func_80000DFC(A *a0) {
    a0->unk4654(a0);
    func_80B07B3C(a0->unk148);
}

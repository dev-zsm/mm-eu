#include "types.h"

typedef struct { u8 pad0[0x190]; void (*unk190)(); } A;
extern void func_80BBB6B0();

void func_800003CC(A *a, s32 b) {
    a->unk190(a, b);
    func_80BBB6B0(a, b);
}

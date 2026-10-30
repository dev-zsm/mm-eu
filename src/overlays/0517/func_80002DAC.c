#include "types.h"

typedef struct { u8 pad0[0x2AC]; void *unk2AC; s16 unk2B0; } A;
extern void func_80B6AB38();
extern u8 D_80B6D098[];

void func_80002DAC(A *a) {
    func_80B6AB38(a, 4);
    a->unk2B0 = 4;
    a->unk2AC = D_80B6D098;
}

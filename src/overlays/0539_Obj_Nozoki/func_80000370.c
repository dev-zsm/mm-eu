#include "types.h"

typedef struct {
    u8 pad0[0x68];
    f32 unk68;
    u8 pad6C[0xF2];
    u8 unk15E;
} Ovl0539Actor;

extern void func_80B871C0();
extern u8 D_80B8767C[];

void func_80000370(Ovl0539Actor *a) {
    func_80B871C0(a, D_80B8767C);
    a->unk15E = 0;
    a->unk68 = 0.0f;
}

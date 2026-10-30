#include "types.h"

typedef struct {
    u8 pad0[0x22C];
    void *unk22C;
} A;

extern u8 D_80BC8B9C[];
extern u8 D_6000168[];
// matching: f32 only reproduces the addiu of the constant 0 in a2, not the real type
void func_80137934(void *, void *, f32, void *);

void func_80000240(A *a) {
    a->unk22C = D_80BC8B9C;
    func_80137934((u8 *)a + 0x164, D_6000168, 0, a);
}

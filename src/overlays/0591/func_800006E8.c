#include "types.h"

// matching: f32 only reproduces the addiu of the constant 0 in a2, not the real type
extern void func_80137934(void *, void *, f32, void *);
extern u8 D_80BC9044[];
extern u8 D_6000168[];

typedef struct { u8 pad0[0x164]; u8 unk164; u8 pad165[0x22C - 0x165]; void *unk22C; } A;

void func_800006E8(A *this) {
    this->unk22C = D_80BC9044;
    func_80137934(&this->unk164, D_6000168, 0.0f, this);
}

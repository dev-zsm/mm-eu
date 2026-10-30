#include "types.h"

extern void func_80B7F0E8();

typedef struct A { u8 pad0[0x1A8]; void (*unk1A8)(struct A *, s32); } A;

void func_80000338(A *this, s32 play) {
    this->unk1A8(this, play);
    func_80B7F0E8(this, play);
}

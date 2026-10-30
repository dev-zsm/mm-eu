#include "types.h"

extern s32 func_80137C58(void *, f32);
extern void func_800B8C4C();

typedef struct { u8 pad0[0x14C]; u8 unk14C; } A;

void func_80000888(A *this, f32 speed) {
    if (func_80137C58(&this->unk14C, speed) != 0) {
        func_800B8C4C(this, 0x28D8);
    }
}

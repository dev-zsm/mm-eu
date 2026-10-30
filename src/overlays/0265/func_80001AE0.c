#include "types.h"
typedef struct { u8 pad0[0x15C]; f32 unk15C; u8 pad160[0x1F0]; f32 unk350; } A;
void func_8099413C();
void func_80001AE0(A *a0, s32 a1) {
    f32 x = a0->unk15C;
    if (x >= a0->unk350) {
        func_8099413C();
    }
}

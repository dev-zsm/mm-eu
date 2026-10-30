#include "types.h"
typedef struct { u8 pad0[0x15C]; f32 unk15C; u8 pad160[0x1FC]; f32 unk35C; } A;
void func_80A61EFC();
void func_800008B0(A *a0, s32 a1) {
    f32 x = a0->unk15C;
    if (x >= a0->unk35C) {
        func_80A61EFC();
    }
}

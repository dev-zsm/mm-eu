#include "types.h"

typedef struct { u8 pad0[0x15C]; f32 unk15C; u8 pad160[0x164]; f32 unk2C4; } A;
extern void func_80BF160C();

void func_800020F4(A *a, s32 b) {
    f32 x = a->unk15C;
    if (a->unk2C4 <= x) {
        func_80BF160C();
    }
}

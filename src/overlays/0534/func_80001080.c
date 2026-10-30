#include "types.h"
extern u8 D_80B822A8[];
void func_80001080(u8 *a0, s32 a1) {
    *(u16 *)(a0 + 0x172) &= ~2;
    *(u16 *)(a0 + 0x172) |= 0x10;
    *(u8 **)(a0 + 0x15C) = D_80B822A8;
    *(f32 *)(a0 + 0x174) = 240.0f;
}

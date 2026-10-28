#include "types.h"

extern u8 D_80BBD910[];

void func_800008A0(u8 *a0) {
    *(u8 **)(a0 + 0x1D4) = D_80BBD910;
    *(f32 *)(a0 + 0x74) = -2.0f;
}

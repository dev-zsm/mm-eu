#include "types.h"

extern u8 D_80B61E70[];

void func_800008A0(u8 *a0) {
    *(u8 **)(a0 + 0x2AC) = D_80B61E70;
    *(f32 *)(a0 + 0x70) = 6.0f;
}

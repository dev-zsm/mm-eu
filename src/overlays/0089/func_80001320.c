#include "types.h"

extern u8 D_808AD384[];

void func_80001320(u8 *a0) {
    *(s16 *)(a0 + 0x1DC) = 0x3C;
    *(u8 **)(a0 + 0x1D0) = D_808AD384;
    *(f32 *)(a0 + 0x70) = 0.0f;
}

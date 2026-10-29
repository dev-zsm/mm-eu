#include "types.h"

extern f32 D_808D3060;
extern u8 D_808D0D20;

void func_80000F9C(u8 *a0) {
    *(s16 *)(a0 + 0x18E) = 0x19;
    *(f32 *)(a0 + 0x74) = D_808D3060;
    *(u8 **)(a0 + 0x188) = &D_808D0D20;
    *(f32 *)(a0 + 0x70) = 0.5f;
}

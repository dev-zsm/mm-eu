#include "types.h"

extern f32 D_80BEFEBC;
extern u8 D_80BEF8E4[];

void func_800003D4(u8 *a0) {
    *(s16 *)(a0 + 0x164) = 0x6E;
    *(f32 *)(a0 + 0x28) = *(f32 *)(a0 + 0xC) + D_80BEFEBC;
    *(u8 **)(a0 + 0x160) = D_80BEF8E4;
}

#include "types.h"

extern u8 D_80B1577C[];

void func_80000F1C(u8 *a0) {
    *(u32 *)(a0 + 4) |= 0x10;
    *(u8 **)(a0 + 0x3C8) = D_80B1577C;
}

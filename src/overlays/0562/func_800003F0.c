#include "types.h"

extern u8 D_80BAE420[];

void func_800003F0(u8 *a0) {
    *(s16 *)(a0 + 0x274) = 0;
    *(s16 *)(a0 + 0x270) = 1;
    *(u8 **)(a0 + 0x254) = D_80BAE420;
}

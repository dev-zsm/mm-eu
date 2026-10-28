#include "types.h"
extern u8 D_80A01568[];
void func_80001448(u8 *a0) {
    *(s32 *)(a0 + 0x1E4) = (s32)D_80A01568;
    *(u8 *)(a0 + 0x1EA) |= 1;
}

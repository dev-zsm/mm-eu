#include "types.h"

extern u8 D_808BF11C[];

void func_800007F8(u8 *a0) {
    *(u8 *)(a0 + 0x24D) = 0;
    *(u8 *)(a0 + 0x395) &= 0xFFFE;
    *(u8 **)(a0 + 0x248) = D_808BF11C;
}

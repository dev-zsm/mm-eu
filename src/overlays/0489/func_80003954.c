#include "types.h"

extern s32 D_80B33670;
extern u8 D_80B2C054[];

void func_80003954(u8 *a0) {
    D_80B33670 = 4;
    *(u8 **)(a0 + 0x2EC) = D_80B2C054;
}

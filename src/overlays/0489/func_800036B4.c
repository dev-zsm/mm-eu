#include "types.h"

extern s32 D_80B33670;
extern u8 D_80B2BDB4[];

void func_800036B4(u8 *a0) {
    D_80B33670 = 3;
    *(u8 **)(a0 + 0x2EC) = D_80B2BDB4;
}

// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern u8 D_80AA9A5C;
void func_800B8C4C();
void func_80000400(u8 *a) {
    *(s32 *)(a + 0x160) = 0x32;
    func_800B8C4C(a, 0x2944);
    *(u8 **)(a + 0x15C) = &D_80AA9A5C;
}

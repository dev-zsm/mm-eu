// FLAGS: -O2 -g0
#include "types.h"

extern void func_80087CB0(void *a, s32 b, s32 c);
extern u8 D_8009E7C8[];

void func_8008C3C4(void) {
    func_80087CB0(D_8009E7C8, 0, 0);
}

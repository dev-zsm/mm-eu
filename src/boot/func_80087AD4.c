// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern void func_80087AA0(void *a0, s32 a1, void *a2);

void func_80087AD4(void *a0, s32 a1, ...) {
    func_80087AA0(a0, a1, (char *)&a1 + 4);
}

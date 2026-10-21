// FLAGS: -O2 -g0
#include "types.h"

extern u8 D_8009D288[];
void func_80087CB0(void *a, s32 b, s32 c);

void func_80089CD4(void) {
    func_80087CB0(D_8009D288, 0, 0);
}

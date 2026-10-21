// FLAGS: -O2 -g0
#include "types.h"

extern s32 D_8009D0F0;
void *func_8008743C(s32 *p, u32 n);
void func_800897D0(void *a, u32 b);

void *func_80086EE8(u32 a0, u32 a1) {
    void *p;
    u32 size = a0 * a1;
    p = func_8008743C(&D_8009D0F0, size);
    if (p != 0) {
        func_800897D0(p, size);
    }
    return p;
}

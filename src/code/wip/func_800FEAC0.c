
#include "types.h"
void func_800897D0(void *, s32);
u8 *func_800FEAC0(u8 *p, s32 v, s32 n) {
    u8 *q;
    s32 i;
    if (v == 0) {
        func_800897D0(p, n);
    } else {
        q = p;
        for (i = n; i > 0; i--) { *q++ = v; }
    }
    return p;
}

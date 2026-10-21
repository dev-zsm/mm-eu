// FLAGS: -O2 -g0
#include "types.h"

extern void func_80087634(void *a0, s32 a1);
extern u8 D_8009D0F0[];

void func_80086380(s32 a0) {
    if (a0 != 0) {
        func_80087634(D_8009D0F0, a0);
    }
}

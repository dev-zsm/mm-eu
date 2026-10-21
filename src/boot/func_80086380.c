// FLAGS: -O2 -g0
#include "types.h"

extern void Arena_Free(void *a0, s32 a1);
extern u8 D_8009D0F0[];

void func_80086380(s32 a0) {
    if (a0 != 0) {
        Arena_Free(D_8009D0F0, a0);
    }
}

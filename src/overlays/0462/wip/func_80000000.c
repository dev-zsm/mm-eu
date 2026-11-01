// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern void func_800B8C4C();

void func_80000000(u8 *a0, u16 a1) {
    if (*(s8 *)(a0 + 0x1B2) <= 0) {
        func_800B8C4C(a0, a1);
    }
}

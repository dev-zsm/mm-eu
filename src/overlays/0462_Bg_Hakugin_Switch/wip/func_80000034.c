#include "types.h"

extern void func_800B8D94();

void func_80000034(u8 *a0, u16 a1) {
    if (*(s8 *)(a0 + 0x1B2) <= 0) {
        func_800B8D94(a0, a1);
    }
}

#include "types.h"

extern void func_800B8C4C();

void func_80001014(u8 *a0) {
    if (*(s16 *)(a0 + 0x318) == 1) {
        func_800B8C4C(a0, 0x38F2);
    }
}

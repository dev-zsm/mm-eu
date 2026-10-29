#include "types.h"

s32 func_80000000(u8 *a) {
    u8 *p = a + 0x18000;
    return *(s8 *)(p + 0x875) != 0 || p[0xB4A] != 0;
}

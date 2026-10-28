#include "types.h"
void func_80005F24(u8 *a0, s32 a1) {
    if (a1 < *(s8 *)(a0 + 0xD5C)) {
        *(s8 *)(a0 + 0xD5C) = a1;
    }
    *(u8 *)(a0 + 0xB5F) = 0;
}

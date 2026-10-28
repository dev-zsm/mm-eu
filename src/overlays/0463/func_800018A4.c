#include "types.h"
void func_800018A4(u8 *a0, s32 a1) {
    if (*(u8 *)(a0 + 0x11C) == 0) {
        *(s32 *)(a0 + 0x280) = *(s32 *)(a0 + 0x284);
    }
}

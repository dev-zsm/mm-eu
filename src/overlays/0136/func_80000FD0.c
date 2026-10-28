#include "types.h"
extern u8 D_80901B80[];
void func_80000FD0(u8 *a0) {
    *(s16 *)(a0 + 0x24C) = 0x40;
    *(s32 *)(a0 + 0x248) = (s32)D_80901B80;
    *(s32 *)(a0 + 0x13C) = 0;
}

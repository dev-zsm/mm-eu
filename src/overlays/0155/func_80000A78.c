#include "types.h"
extern u8 D_80920158[];
void func_80000A78(u8 *a0, s32 a1, s32 a2, s32 a3) {
    *(s32 *)(a0 + 0x174) = a2;
    *(u8 *)(a0 + 0x171) = a3;
    *(s32 *)(a0 + 0x15C) = (s32)D_80920158;
}

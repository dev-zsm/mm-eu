#include "types.h"

extern void func_800B8C4C();

void func_800000A0(u8 *a0, u8 *a1, s32 a2) {
    *(s16 *)(a0 + 0x15C) = a1[0x1E];
    *(u8 *)(a0 + 0x15F) = a1[0x1C];
    if (a2 == 0) {
        func_800B8C4C(a0, 0x2859);
    }
}

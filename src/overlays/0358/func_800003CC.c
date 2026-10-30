#include "types.h"
extern s32 D_80A506F4;
void func_800003CC(u8 *a0) {
    s32 v = *(s32 *)(a0 + 0x30C);
    if (v & 0x100) {
        *(s32 *)(a0 + 0x30C) = v & ~0x100;
        D_80A506F4 -= 1;
    }
}

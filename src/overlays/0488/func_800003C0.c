#include "types.h"
void func_80B25868(void *, s16, s32, f32);
void func_800003C0(u8 *a0, s16 a1) {
    if (a1 != *(s16 *)(a0 + 0x2D2)) {
        func_80B25868(a0, a1, 0, -5.0f);
    }
}

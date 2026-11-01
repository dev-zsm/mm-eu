#include "types.h"

extern s16 func_800B6A58();

void func_800000D0(void *a0, u8 *a1) {
    *(f32 *)(a1 + 0x2F0) = 30.0f;
    *(s16 *)(a1 + 0x2F4) = func_800B6A58(a0);
}

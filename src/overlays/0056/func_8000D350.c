#include "types.h"

extern s32 func_80839F50(void *a0, void *a1, f32 a2);

void func_8000D350(void *a0, u8 *a1) {
    if (func_80839F50(a0, a1, 180.0f) != 0) {
        *(s16 *)(a1 + 0xAE8) = -0x14;
    }
}

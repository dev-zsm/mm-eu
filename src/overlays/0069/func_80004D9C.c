#include "types.h"

extern void func_8087F9F0(u8 *a0, s32 a1, f32 a2, f32 a3);

void func_80004D9C(u8 *a0) {
    *(s32 *)(a0 + 0x20C) = 4;
    func_8087F9F0(a0, 4, 0.0f, 0.0f);
}

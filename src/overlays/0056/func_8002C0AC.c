#include "types.h"

extern void func_80840684(s32, s16 *, s32, f32, s32, s32);

void func_8002C0AC(s32 a, s16 *b, s32 c) {
    b[0xC2 / 2] = 0xF;
    func_80840684(a, b, c, 0, 0, 0);
}

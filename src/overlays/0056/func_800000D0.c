#include "types.h"

extern void func_80136A4C(s32, s32, s32, f32);

void func_800000D0(s32 a0, s32 a1, s32 a2) {
    func_80136A4C(a0, a1 + 0x240, a2, 0.6666667f);
}

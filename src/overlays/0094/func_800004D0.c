// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern void func_800FD0AC(s32, f32, f32, f32, f32);

void func_800004D0(s32 a0, f32 a1) {
    func_800FD0AC(a0, a1, 850.0f, 0.2f, 0.0f);
}

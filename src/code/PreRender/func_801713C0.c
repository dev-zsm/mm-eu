// FLAGS: -O2 -g0 -mips2
#include "types.h"

void func_80171150(s32, s32, s32, s32, s32, s32, s32, s32);

void func_801713C0(s32 a0, s32 a1, s32 a2, s32 a3) {
    func_80171150(a0, a1, a2, a3, 0xFF, 0xFF, 0xFF, 0xFF);
}

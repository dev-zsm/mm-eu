// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern void func_80831B9C(s32 a0, s32 a1, s32 a2, s32 a3);

void func_80004AC8(s32 a0, s32 a1, s32 a2) {
    func_80831B9C(a0, a1, a2, -1);
}

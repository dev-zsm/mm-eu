// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern void func_80177194(s32 a0, s32 a1);

void func_80081EC8(s32 a0) {
    func_80177194(a0, 0);
}

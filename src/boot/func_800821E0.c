// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern void func_800820D8(s32 x, s32 y, s32 w, s32 h, u16 c);

void func_800821E0(u16 c) {
    func_800820D8(0x16, 0x10, 8, 1, c);
}

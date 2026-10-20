// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern void func_80083F24(s32 x0, s32 y0, s32 x1, s32 y1, u16 c);

void func_800820D8(s32 x, s32 y, s32 w, s32 h, u16 c) {
    func_80083F24(x, y, x + w - 1, y + h - 1, c);
}

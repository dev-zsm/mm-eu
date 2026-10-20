// FLAGS: -O1 -g0 -mips2
#include "types.h"
void func_800886B0(s32 a, s32 b);

void func_80092400(s32 arg0) {
    func_800886B0((u16)(arg0 + 0x4000), arg0);
}

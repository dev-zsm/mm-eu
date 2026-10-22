// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 func_800B1300(s32, s32, s32, s32, s32, s32, s32, s32);

void func_800B1880(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    func_800B1300(a0, a1, a2, a3, a4, a5, 0x64, 5);
}

// FLAGS: -O2 -g0 -mips2
#include "types.h"

s32 func_8019165C(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
void func_80087CB0(s32 a0, s32 a1, s32 a2);

void AudioLoad_AsyncLoad(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    if (func_8019165C(a0, a1, a2, a3, a4) == 0) {
        func_80087CB0(a4, -1, 0);
    }
}

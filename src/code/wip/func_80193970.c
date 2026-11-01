// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 D_801CE91C;
extern s32 D_801F49D8[];
extern u8 D_801F4980[];
extern void AudioLoad_AsyncLoad(s32 arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4);

void func_80193970(s32 arg0, s32 arg1, s32 arg2) {
    s32 idx = D_801CE91C;

    D_801F49D8[idx] = arg2;
    AudioLoad_AsyncLoad(arg0, arg1, 0, idx, D_801F4980);
    idx = D_801CE91C + 1;
    D_801CE91C = idx;
    if (idx == 0x10) {
        D_801CE91C = 0;
    }
}

// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern s32 AudioThread_GetSamplePos();
s32 AudioThread_GetSamplePosFromStart(s32 a0, s32 a1, s32 a2) {
    s32 pad;
    s32 sp28;
    s32 sp24;
    if (AudioThread_GetSamplePos(a0, a1, a2, &sp28, &sp24) == 0) {
        return 0;
    }
    return sp24;
}

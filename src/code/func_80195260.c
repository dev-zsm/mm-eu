// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 AudioThread_GetSamplePos(s32 arg0, s32 arg1, s32 arg2, s32 *end, s32 *start);

s32 AudioThread_GetSamplePosUntilEnd(s32 arg0, s32 arg1, s32 arg2) {
    s32 pad; // unused slot: pads the frame to the ROM size
    s32 end;
    s32 start;

    if (AudioThread_GetSamplePos(arg0, arg1, arg2, &end, &start) == 0) {
        return 0;
    }
    return end - start;
}

// FLAGS: -O2 -g3 -mips2
#include "types.h"

void Play_ClearCamera(void *, s16);

void Play_ClearAllSubCameras(void *arg0) {
    s16 var_s0 = 1;
    do {
        if (*(s32 *)((u8 *)arg0 + var_s0 * 4 + 0x800) != 0) {
            Play_ClearCamera(arg0, var_s0);
        }
        var_s0 += 1;
    } while (var_s0 < 4);
    *(s16 *)((u8 *)arg0 + 0x810) = 0;
}

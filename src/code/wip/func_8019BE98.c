#include "types.h"

extern u8 D_801D0E58;
extern s32 D_801CF91C;

u8 AudioOcarina_GetPlayingState(void) {
    u8 state = D_801D0E58;
    s32 ret;

    if (state != 0) {
        ret = state - 1;
        D_801D0E58 = 0;
        return ret;
    }
    if (D_801CF91C != 0) {
        return 0xFE;
    }
    ret = 0xFF;
    return ret;
}

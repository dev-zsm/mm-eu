// FLAGS: -O2 -g0 -mips2
#include "os_vi.h"

void osViBlack(u8 active) {
    OSIntMask mask;

    mask = __osDisableInt();
    if (active != 0) {
        D_800982B4->state |= VI_STATE_BLACK;
    } else {
        D_800982B4->state &= ~VI_STATE_BLACK;
    }
    __osRestoreInt(mask);
}

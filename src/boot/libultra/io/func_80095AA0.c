// FLAGS: -O2 -g0 -mips2
#include "os_vi.h"

void osViSetYScale(f32 value) {
    OSIntMask mask;

    mask = __osDisableInt();
    D_800982B4->y.factor = value;
    D_800982B4->state |= VI_STATE_Y_SCALE;
    __osRestoreInt(mask);
}

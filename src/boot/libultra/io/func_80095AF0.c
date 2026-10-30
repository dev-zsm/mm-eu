// FLAGS: -O2 -g0 -mips2
#include "os_vi.h"

void osViSetXScale(f32 value) {
    OSIntMask mask;
    u32 xScale;

    mask = __osDisableInt();
    D_800982B4->x.factor = value;
    D_800982B4->state |= VI_STATE_X_SCALE;
    xScale = D_800982B4->modep->comRegs.xScale;
    /* matching: the factor is read back through a cast of the global */
    D_800982B4->x.scale = (u32)((f32)(xScale & 0xFFF) * (*(OSViContext **)&D_800982B4)->x.factor) & 0xFFF;
    __osRestoreInt(mask);
}

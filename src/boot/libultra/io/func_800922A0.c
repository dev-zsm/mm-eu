// FLAGS: -O2 -g0 -mips2
#include "os_vi.h"

void osViSetSpecialFeatures(u32 func) {
    OSIntMask mask;

    mask = __osDisableInt();
    if (func & 1) {
        D_800982B4->control |= 8;
    }
    if (func & 2) {
        D_800982B4->control &= ~8;
    }
    if (func & 4) {
        D_800982B4->control |= 4;
    }
    if (func & 8) {
        D_800982B4->control &= ~4;
    }
    if (func & 0x10) {
        D_800982B4->control |= 0x10;
    }
    if (func & 0x20) {
        D_800982B4->control &= ~0x10;
    }
    if (func & 0x40) {
        D_800982B4->control |= 0x10000;
        D_800982B4->control &= ~0x300;
    }
    if (func & 0x80) {
        D_800982B4->control &= ~0x10000;
        D_800982B4->control |= D_800982B4->modep->comRegs.ctrl & 0x300;
    }
    D_800982B4->state |= VI_STATE_FEATURES;
    __osRestoreInt(mask);
}

// FLAGS: -O2 -g0 -mips2
#include "os_vi.h"

void osViSetMode(OSViMode *mode) {
    OSIntMask mask;

    mask = __osDisableInt();
    D_800982B4->modep = mode;
    D_800982B4->state = 1;
    D_800982B4->control = D_800982B4->modep->comRegs.ctrl;
    __osRestoreInt(mask);
}

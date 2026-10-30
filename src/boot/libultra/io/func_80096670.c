// FLAGS: -O2 -g0 -mips2
#include "os_vi.h"

void *osViGetCurrentFramebuffer(void) {
    OSIntMask mask;
    void *framep;

    mask = __osDisableInt();
    framep = D_800982B0->framep;
    __osRestoreInt(mask);
    return framep;
}

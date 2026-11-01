// FLAGS: -O2 -g0 -mips2
#include "boot/fault.h"
#include "sdk/os_vi.h"

void *func_8008ABB0(void) {
    OSIntMask mask;
    void *framep;

    mask = __osDisableInt();
    framep = D_800982B4->framep;
    __osRestoreInt(mask);
    return framep;
}

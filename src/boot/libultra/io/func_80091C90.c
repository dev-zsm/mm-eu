// FLAGS: -O2 -g0 -mips2
#include "os_vi.h"
#include "libc.h"

void __osViInit(void) {
    u32 tvType;

    bzero(&D_80098250, 0x60);
    D_800982B0 = &D_80098250;
    D_800982B4 = &D_80098280;
    D_800982B4->retraceCount = 1;
    D_800982B0->retraceCount = 1;
    D_800982B4->framep = (void *)0x80000000;
    D_800982B0->framep = (void *)0x80000000;
    tvType = D_80000300;
    if (tvType == 0) {
        D_800982B4->modep = &D_80097780;
    } else if (tvType == 2) {
        D_800982B4->modep = &D_80098200;
    } else {
        D_800982B4->modep = &D_800981B0;
    }
    D_800982B4->state = 0x20;
    D_800982B4->control = D_800982B4->modep->comRegs.ctrl;
    if (IO_READ(VI_CURRENT_REG) >= 0xB) {
        do {} while (IO_READ(VI_CURRENT_REG) >= 0xB);
    }
    IO_WRITE(VI_CONTROL_REG, 0);
    __osViSwapContext();
}

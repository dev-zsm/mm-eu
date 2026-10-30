// FLAGS: -O2 -g0 -mips2
#include "os_vi.h"

void osViSwapBuffer(void *frameBuf) {
    OSIntMask mask;

    mask = __osDisableInt();
    D_800982B4->framep = frameBuf;
    D_800982B4->state = (u16)(D_800982B4->state | VI_STATE_SWAP_FRAMEBUFFER);
    __osRestoreInt(mask);
}

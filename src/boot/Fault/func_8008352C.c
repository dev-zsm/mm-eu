// FLAGS: -O2 -g3 -mips2 -trapuv
#include "fault.h"
#include "os_internal.h"
#include "os_vi.h"

void Fault_DisplayFrameBuffer(void) {
    void *fb;

    osViSetYScale(1.0f);
    osViSetMode(&D_800981B0);
    osViSetSpecialFeatures(OS_VI_GAMMA_OFF | OS_VI_DITHER_FILTER_ON);
    osViBlack(0);
    if (D_8009C220->fb != NULL) {
        fb = D_8009C220->fb;
    } else {
        fb = func_8008ABB0();
        if ((u32)fb == 0x80000000) {
            fb = (void *)((D_80000318 | 0x80000000) + 0xFFFDA800);
        }
    }
    osViSwapBuffer(fb);
    FaultDrawer_SetDrawerFrameBuffer(fb, 320, 240);
}

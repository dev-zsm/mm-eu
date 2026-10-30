// FLAGS: -O2 -g3 -mips2
#include "faultdrawer.h"

void FaultDrawer_SetDrawerFrameBuffer(void *fb, u16 w, u16 h) {
    D_80096D80->fb = fb;
    D_80096D80->w = w;
    D_80096D80->h = h;
}

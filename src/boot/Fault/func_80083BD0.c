// FLAGS: -O2 -g3 -mips2 -trapuv
#include "fault.h"

void Fault_SetFrameBuffer(void *fb, u16 w, u16 h) {
    D_8009C220->fb = fb;
    FaultDrawer_SetDrawerFrameBuffer(fb, w, h);
}

// FLAGS: -O2 -g3 -mips2 -trapuv
#include "fault.h"

void Fault_DrawRec(s32 x, s32 y, s32 w, s32 h, u16 color) {
    FaultDrawer_DrawRecImpl(x, y, x + w - 1, y + h - 1, color);
}

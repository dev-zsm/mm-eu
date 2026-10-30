// FLAGS: -O2 -g3 -mips2 -trapuv
#include "fault.h"

void Fault_DrawCornerRec(u16 color) {
    Fault_DrawRec(22, 16, 8, 1, color);
}

// FLAGS: -O2 -g0 -mips2 -trapuv
#include "fault.h"

void Fault_FillScreenBlack(void) {
    FaultDrawer_SetForeColor(FAULT_COLOR_WHITE);
    FaultDrawer_SetBackColor(FAULT_COLOR_BLACK);
    FaultDrawer_FillScreen();
    FaultDrawer_SetBackColor(0);
}

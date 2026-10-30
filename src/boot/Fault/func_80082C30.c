// FLAGS: -O2 -g3 -mips2 -trapuv
#include "fault.h"

void Fault_WaitForButtonCombo(void) {
    Input *input = &D_8009C220->padInput[0];

    FaultDrawer_SetForeColor(FAULT_COLOR_WHITE);
    FaultDrawer_SetBackColor(FAULT_COLOR_BLACK);
    do {
        do {
            Fault_Sleep(0x10);
            Fault_UpdatePadImpl();
        } while (!CHECK_BTN_ALL(input->press.button, BTN_RESET));
    } while (!CHECK_BTN_ALL(input->cur.button, BTN_DLEFT | BTN_L | BTN_R | BTN_CRIGHT));
}

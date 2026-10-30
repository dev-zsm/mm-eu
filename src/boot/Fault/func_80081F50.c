// FLAGS: -O2 -g3 -mips2 -trapuv
#include "fault.h"

s32 Fault_WaitForInputImpl(void) {
    Input *volatile input; /* matching: volatile keeps the pointer in its stack slot like the ROM */
    s32 count;
    u32 pressedBtn;

    input = D_8009C220->padInput;
    count = 600;
    while (1) {
        Fault_Sleep(0x10);
        Fault_UpdatePadImpl();
        pressedBtn = input->press.button;
        if (pressedBtn == BTN_L) {
            D_8009C220->autoScroll = !D_8009C220->autoScroll;
        }
        if (D_8009C220->autoScroll) {
            if (count-- < 1) {
                return 0;
            }
            continue;
        }
        if (pressedBtn == BTN_A || pressedBtn == BTN_DRIGHT) {
            return 0;
        }
        if (pressedBtn == BTN_DLEFT) {
            return 1;
        }
        if (pressedBtn == BTN_DUP) {
            FaultDrawer_SetOsSyncPrintfEnabled(1);
        }
        if (pressedBtn == BTN_DDOWN) {
            FaultDrawer_SetOsSyncPrintfEnabled(0);
        }
    }
}

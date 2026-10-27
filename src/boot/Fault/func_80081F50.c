// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"
extern u8 *D_8009C220;
extern void Fault_Sleep(s32 a);
extern void Fault_UpdatePadImpl(void);
extern void FaultDrawer_SetOsSyncPrintfEnabled(s32 a);
s32 Fault_WaitForInputImpl(void) {
    u16 * volatile ptr; /* volatile: forces the pointer to live in its stack slot like the ROM */
    s32 timeout;
    s32 btn;
    ptr = (u16 *)(D_8009C220 + 0x7E4);
    timeout = 0x258;
    for (;;) {
        Fault_Sleep(0x10);
        Fault_UpdatePadImpl();
        btn = ptr[6];
        if (0x20 == btn) {
            D_8009C220[0x7CF] = !D_8009C220[0x7CF];
        }
        if (D_8009C220[0x7CF] != 0) {
            if (timeout-- < 1) return 0;
            continue;
        }
        if (0x8000 == btn || 0x100 == btn) return 0;
        if (0x200 == btn) return 1;
        if (0x800 == btn) FaultDrawer_SetOsSyncPrintfEnabled(1);
        if (0x400 == btn) FaultDrawer_SetOsSyncPrintfEnabled(0);
    }
}

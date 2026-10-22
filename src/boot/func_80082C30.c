// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

typedef struct {
    u16 unk0;
    u8 pad2[0xA];
    u16 unkC;
} Hw;

extern void FaultDrawer_SetForeColor(s32);
extern void FaultDrawer_SetBackColor(s32);
extern void Fault_Sleep(s32);
extern void Fault_UpdatePadImpl(void);
extern u8 *D_8009C220;

void Fault_WaitForButtonCombo(void) {
    Hw *s0;

    s0 = (Hw *)(D_8009C220 + 0x7E4);
    FaultDrawer_SetForeColor(0xFFFF);
    FaultDrawer_SetBackColor(1);
    do {
loop:
        Fault_Sleep(0x10);
        Fault_UpdatePadImpl();
        if (~(s0->unkC | -0x81) != 0) {
            goto loop;
        }
    } while (~(s0->unk0 | -0x232) != 0);
}

// FLAGS: -O2 -g0 -mips2 -trapuv
#include "types.h"

extern void FaultDrawer_SetForeColor(s32 a);
extern void FaultDrawer_SetBackColor(s32 a);
extern void FaultDrawer_FillScreen(void);

void Fault_FillScreenBlack(void) {
    FaultDrawer_SetForeColor(0xFFFF);
    FaultDrawer_SetBackColor(1);
    FaultDrawer_FillScreen();
    FaultDrawer_SetBackColor(0);
}

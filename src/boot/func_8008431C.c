// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern u8 *D_80096D80;

void FaultDrawer_UpdatePrintColor(void);

void FaultDrawer_SetForeColor(u16 a0) {
    *(u16 *)(D_80096D80 + 0x10) = a0;
    FaultDrawer_UpdatePrintColor();
}

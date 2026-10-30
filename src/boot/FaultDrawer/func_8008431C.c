// FLAGS: -O2 -g3 -mips2 -trapuv
#include "faultdrawer.h"

void FaultDrawer_SetForeColor(u16 color) {
    D_80096D80->foreColor = color;
    FaultDrawer_UpdatePrintColor();
}

// FLAGS: -O2 -g3 -mips2 -trapuv
#include "faultdrawer.h"

void FaultDrawer_SetBackColor(u16 color) {
    D_80096D80->backColor = color;
    FaultDrawer_UpdatePrintColor();
}

// FLAGS: -O2 -g3 -mips2 -trapuv
#include "faultdrawer.h"
#include "fault.h"

void FaultDrawer_FillScreen(void) {
    if (D_80096D80->osSyncPrintfEnabled) {
        func_8008198C(D_80099300);
    }
    FaultDrawer_DrawRecImpl(D_80096D80->xStart, D_80096D80->yStart, D_80096D80->xEnd, D_80096D80->yEnd,
                            D_80096D80->backColor | 1);
    FaultDrawer_SetCursor(D_80096D80->xStart, D_80096D80->yStart);
}

// FLAGS: -O2 -g3 -mips2 -trapuv
#include "faultdrawer.h"
#include "fault.h"

void FaultDrawer_SetCursor(s32 x, s32 y) {
    if (D_80096D80->osSyncPrintfEnabled) {
        func_8008198C(D_800992F4, (y - D_80096D80->yStart) / (D_80096D80->charH + D_80096D80->charHPad),
                      (x - D_80096D80->xStart) / (D_80096D80->charW + D_80096D80->charWPad));
    }
    D_80096D80->cursorX = x;
    D_80096D80->cursorY = y;
}

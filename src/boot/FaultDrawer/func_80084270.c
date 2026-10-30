// FLAGS: -O2 -g3 -mips2 -trapuv
#include "faultdrawer.h"
#include "fault.h"

void FaultDrawer_UpdatePrintColor(void) {
    s32 idx;

    if (!D_80096D80->osSyncPrintfEnabled) {
        return;
    }
    func_8008198C(D_800992E0);
    idx = FaultDrawer_ColorToPrintColor(D_80096D80->foreColor);
    if (idx >= 0 && idx < 8) {
        func_8008198C(D_800992E4, idx);
    }
    idx = FaultDrawer_ColorToPrintColor(D_80096D80->backColor);
    if (idx >= 0 && idx < 8) {
        func_8008198C(D_800992EC, idx);
    }
}

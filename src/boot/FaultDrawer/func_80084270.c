// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern u8 *D_80096D80;
extern u8 D_800992E0[];
extern u8 D_800992E4[];
extern u8 D_800992EC[];

s32 FaultDrawer_ColorToPrintColor(s32 a0);
void func_8008198C(void *fmt, ...);

void FaultDrawer_UpdatePrintColor(void) {
    s32 idx;

    if (D_80096D80[0x35] == 0) {
        return;
    }
    func_8008198C(D_800992E0);
    idx = FaultDrawer_ColorToPrintColor(*(u16 *)(D_80096D80 + 0x10));
    if (idx >= 0 && idx < 8) {
        func_8008198C(D_800992E4, idx);
    }
    idx = FaultDrawer_ColorToPrintColor(*(u16 *)(D_80096D80 + 0x12));
    if (idx >= 0 && idx < 8) {
        func_8008198C(D_800992EC, idx);
    }
}

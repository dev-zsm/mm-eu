// FLAGS: -O2 -g3 -mips2 -trapuv
#include "fault.h"

void Fault_DrawMemDumpContents(const char *title, u32 addr, u32 arg2) {
    u32 alignedAddr = addr;
    u32 *writePtr;
    s32 y;
    s32 x;

    if (alignedAddr < 0x80000000) {
        alignedAddr = 0x80000000;
    }
    if (alignedAddr > 0x807FFF00) {
        alignedAddr = 0x807FFF00;
    }
    alignedAddr &= ~3;
    writePtr = (u32 *)alignedAddr;
    Fault_FillScreenBlack();
    FaultDrawer_SetCharPad(-2, 0);
    FaultDrawer_DrawText(36, 18, D_80098BE4, title != NULL ? title : D_80098BEC, alignedAddr);
    if (alignedAddr >= 0x80000000 && alignedAddr < 0xC0000000) {
        for (y = 28; y != 226; y += 9) {
            FaultDrawer_DrawText(24, y, D_80098BF8, writePtr);
            for (x = 82; x != 290; x += 52) {
                FaultDrawer_DrawText(x, y, D_80098C00, *writePtr++);
            }
        }
    }
    FaultDrawer_SetCharPad(0, 0);
}

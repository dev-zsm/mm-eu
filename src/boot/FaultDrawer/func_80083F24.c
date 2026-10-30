// FLAGS: -O2 -g3 -mips2 -trapuv
#include "faultdrawer.h"
#include "fault.h"

void FaultDrawer_DrawRecImpl(s32 xStart, s32 yStart, s32 xEnd, s32 yEnd, u16 color) {
    s32 x;
    s32 y;
    s32 xDiff = D_80096D80->w - xStart;
    s32 yDiff = D_80096D80->h - yStart;
    s32 xSize = xEnd - xStart + 1;
    s32 ySize = yEnd - yStart + 1;
    u16 *ptr;

    if (xDiff > 0 && yDiff > 0) {
        if (xDiff < xSize) {
            xSize = xDiff;
        }
        if (yDiff < ySize) {
            ySize = yDiff;
        }
        ptr = D_80096D80->fb + D_80096D80->w * yStart + xStart;
        for (y = 0; y < ySize; y++) {
            for (x = 0; x < xSize; x++) {
                *ptr++ = color;
            }
            ptr += D_80096D80->w - xSize;
        }
        osWritebackDCacheAll();
    }
}

// FLAGS: -O2 -g3 -mips2 -trapuv
#include "faultdrawer.h"

void FaultDrawer_DrawText(s32 x, s32 y, const char *fmt, ...) {
    va_list args;

    args = (va_list)(&fmt + 1);
    FaultDrawer_SetCursor(x, y);
    FaultDrawer_VPrintf(fmt, args);
}

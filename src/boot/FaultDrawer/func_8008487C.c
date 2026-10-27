// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

void FaultDrawer_SetCursor(s32 x, s32 y);
void FaultDrawer_VPrintf(s32 fmt, s32 *args);

void FaultDrawer_DrawText(s32 x, s32 y, s32 fmt, ...) {
    s32 *args;

    args = &fmt + 1;
    FaultDrawer_SetCursor(x, y);
    FaultDrawer_VPrintf(fmt, args);
}

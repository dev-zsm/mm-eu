// FLAGS: -O1 -g3 -mips2 -trapuv
#include "types.h"

void FaultDrawer_VPrintf(s32 a0, s32 *a1);

void FaultDrawer_Printf(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 pad[2];

    FaultDrawer_VPrintf(a0, &a1);
}

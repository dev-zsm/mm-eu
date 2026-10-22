// FLAGS: -O1 -g0 -mips2 -trapuv
#include "types.h"

void FaultDrawer_SetCursor(void);
void FaultDrawer_VPrintf(s32 a0, s32 *a1);

// best attempt: 1 instr differs (ROM has a nop in the jal delay slot, ours spills f12 there)
void FaultDrawer_DrawText(f64 a0, s32 a2, s32 a3) {
    s32 pad[2];

    FaultDrawer_SetCursor();
    FaultDrawer_VPrintf(a2, &a3);
}

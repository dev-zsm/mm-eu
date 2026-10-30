// FLAGS: -O2 -g3 -mips2 -trapuv
#include "fault.h"

void Fault_PrintFPCSR(u32 value) {
    s32 i;
    u32 flag = FPCSR_CAUSE_UNIMPLEMENTED;

    FaultDrawer_Printf(D_80098890, value);
    for (i = 0; i < FPCSR_NUM_CAUSES; i++) {
        if (value & flag) {
            FaultDrawer_Printf(D_800988A0, D_80096D68[i]);
            break;
        }
        flag >>= 1;
    }
    FaultDrawer_Printf(D_800988A8);
}

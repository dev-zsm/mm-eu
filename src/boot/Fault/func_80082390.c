// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern void FaultDrawer_Printf();
extern u8 D_80098890[];
extern u8 D_800988A0[];
extern u8 D_800988A8[];
extern s32 D_80096D68[];

void Fault_PrintFPCSR(u32 arg0) {
    s32 i;
    u32 bit = 0x20000;

    FaultDrawer_Printf(D_80098890, arg0);
    for (i = 0; i != 6; i++) {
        if (arg0 & bit) {
            FaultDrawer_Printf(D_800988A0, D_80096D68[i]);
            break;
        }
        bit >>= 1;
    }
    FaultDrawer_Printf(D_800988A8);
}

// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern void FaultDrawer_Printf();
extern u8 D_80098848[];
extern u8 D_80098858[];

void Fault_PrintFReg(s32 arg0, f32 *arg1) {
    s32 bits;
    s32 exp;

    bits = *(s32 *)arg1;
    exp = (s32)((u32)(bits & 0x7F800000) >> 23) - 0x7F;
    if ((exp >= -0x7E && exp < 0x80) || bits == 0) {
        FaultDrawer_Printf(D_80098848, arg0, (f64)*arg1);
        return;
    }
    FaultDrawer_Printf(D_80098858, arg0, bits);
}

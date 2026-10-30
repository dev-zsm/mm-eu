// FLAGS: -O2 -g3 -mips2 -trapuv
#include "fault.h"

void Fault_PrintFReg(s32 index, f32 *value) {
    s32 bits;
    s32 exp;

    bits = *(s32 *)value;
    exp = (s32)((u32)(bits & 0x7F800000) >> 23) - 0x7F;
    if ((exp >= -0x7E && exp < 0x80) || bits == 0) {
        FaultDrawer_Printf(D_80098848, index, *value);
        return;
    }
    FaultDrawer_Printf(D_80098858, index, bits);
}

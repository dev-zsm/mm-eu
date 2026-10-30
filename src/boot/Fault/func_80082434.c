// FLAGS: -O2 -g3 -mips2 -trapuv
#include "fault.h"

void Fault_LogFPCSR(u32 value) {
    s32 i;
    u32 flag = FPCSR_CAUSE_UNIMPLEMENTED;

    func_8008198C(D_800988AC, value);
    for (i = 0; i < FPCSR_NUM_CAUSES; i++) {
        if (value & flag) {
            func_8008198C(D_800988BC, D_80096D68[i]);
            break;
        }
        flag >>= 1;
    }
}

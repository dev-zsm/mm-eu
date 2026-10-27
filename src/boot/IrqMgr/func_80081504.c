// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern void StackCheck_Check(s32 arg0);

void IrqMgr_CheckStacks(void) {
    StackCheck_Check(0);
}

// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern void IrqMgr_CheckStacks(void);

void IrqMgr_HandlePRENMI500(s32 arg0) {
    IrqMgr_CheckStacks();
}

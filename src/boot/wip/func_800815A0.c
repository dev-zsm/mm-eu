// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern void osSetTimer(void *a, u64 b, s32 c, s32 d, void *e, s32 f);
extern void osAfterPreNMI(void);

void IrqMgr_HandlePRENMI480(u8 *arg0) {
    osSetTimer(arg0 + 0x258, 0x173EED8, 0, 0, arg0 + 0x60, 0x2A1);
    osAfterPreNMI();
}

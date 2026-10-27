// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern void osSetTimer(void *timer, u64 countdown, u64 interval, void *mq, s32 msg);
extern void osAfterPreNMI(void);
void IrqMgr_HandlePRENMI480(u8 *arg0) {
    osSetTimer(arg0 + 0x258, 0x173EED8, 0, arg0 + 0x60, 0x2A1);
    osAfterPreNMI();
}

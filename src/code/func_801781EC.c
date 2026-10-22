// FLAGS: -O2 -g0 -mips2
#include "types.h"

void func_80087CB0(s32, s32, s32);

void Sched_SendNotifyMsg(s32 arg0) {
    func_80087CB0(arg0, 0x29E, 1);
}

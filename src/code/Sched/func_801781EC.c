// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "generated/code_funcs.h"

void func_80087CB0(s32, s32, s32);

void Sched_SendNotifyMsg(struct Scheduler *sched) {
    func_80087CB0(sched, 0x29E, 1);
}

// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern void func_80087CB0();

void Sched_SendAudioCancelMsg(s32 a0) {
    func_80087CB0(a0, 0x29F, 1);
}

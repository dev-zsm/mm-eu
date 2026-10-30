// FLAGS: -O2 -g3 -mips2 -trapuv
#include "fault.h"
#include "os_sp.h"

void Fault_ResumeThread(OSThread *thread) {
    thread->context.cause = 0;
    thread->context.fpcsr = 0;
    thread->context.pc += 4;
    *(u32 *)thread->context.pc = 0xD; /* break */
    func_8008A780((void *)thread->context.pc, 4);
    osInvalICache((void *)thread->context.pc, 4);
    osStartThread(thread);
}

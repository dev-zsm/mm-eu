// FLAGS: -O2 -g3 -mips2 -trapuv
#include "fault.h"
#include "dbg.h"

void Fault_AddHungupAndCrashImpl(const char *exp1, const char *exp2) {
    FaultClient client;
    u8 pad[8]; /* matching: unused, needed for the frame layout */

    func_80081A50(&client, (FaultClientCallback)Fault_HangupFaultClient, (void *)exp1, (void *)exp2);
    *(u32 *)0x11111111 = 0;
}

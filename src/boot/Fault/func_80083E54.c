// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern void Fault_HangupFaultClient(s32 a0, s32 a1);
extern void func_80081A50(void *a0, void *a1, s32 a2, s32 a3);

void Fault_AddHungupAndCrashImpl(s32 a0, s32 a1) {
    u8 buf[0x10];
    u8 pad[0x8]; /* unused, but needed for the frame layout */
    func_80081A50(buf, Fault_HangupFaultClient, a0, a1);
    *(u32 *)0x11111111 = 0;
}

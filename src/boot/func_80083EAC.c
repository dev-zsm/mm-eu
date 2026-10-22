// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern u8 D_80098ED0[];
extern void Fault_AddHungupAndCrashImpl(void *a0, s32 a1);
extern void sprintf(void *a0, void *a1, s32 a2, s32 a3);

void Fault_AddHungupAndCrash(s32 a0, s32 a1) {
    u8 buf[0x100];
    sprintf(buf, D_80098ED0, a0, a1);
    Fault_AddHungupAndCrashImpl(buf, 0);
}

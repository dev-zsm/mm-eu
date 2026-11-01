// FLAGS: -O2 -g3 -mips2 -trapuv
#include "boot/fault.h"
#include "boot/dbg.h"
#include "boot/printf.h"

void Fault_AddHungupAndCrash(const char *file, s32 line) {
    char msg[0x100];

    sprintf(msg, D_80098ED0, file, line);
    Fault_AddHungupAndCrashImpl(msg, NULL);
}

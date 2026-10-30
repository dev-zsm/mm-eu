#include "dbg.h"
#include "ultra64.h"

void _dbg_hungup(const char *file, s32 line) {
    osGetThreadId(NULL);
    Fault_AddHungupAndCrash(file, line);
}

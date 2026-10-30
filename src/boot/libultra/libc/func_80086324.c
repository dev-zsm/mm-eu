// FLAGS: -O2 -g0
#include "dbg.h"
#include "libultra_libc.h"

void Reset(void) {
    Fault_AddHungupAndCrash(D_80099340, 0);
}

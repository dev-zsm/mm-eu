// FLAGS: -O2 -g3 -mips2 -trapuv
#include "fault.h"

void func_800819E0(u32 msec) {
    csleep((u64)msec * OS_CPU_COUNTER / 1000);
}

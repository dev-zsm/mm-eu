// FLAGS: -O2 -g0 -mips2
#include "types.h"

void osDpSetStatus(u32 a0) {
    *(u32 *)0xA410000C = a0;
}

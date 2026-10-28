// FLAGS: -O2 -g0 -mips2
#include "types.h"

u32 osDpGetStatus(void) {
    return *(u32 *)0xA410000C;
}

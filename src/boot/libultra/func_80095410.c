// FLAGS: -O2 -g0 -mips2
#include "types.h"

s32 __osSpGetStatus(void) {
    return *(s32 *)0xA4040010;
}

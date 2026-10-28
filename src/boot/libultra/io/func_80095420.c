// FLAGS: -O2 -g0 -mips2
#include "types.h"

void __osSpSetStatus(s32 a0) {
    *(s32 *)0xA4040010 = a0;
}

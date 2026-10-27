// FLAGS: -O2 -g0 -mips2
#include "types.h"
s32 __osSpSetPc(s32 arg0) {
    s32 temp_v0;
    temp_v0 = *(u32 *)0xA4040010;
    if (!(temp_v0 & 1)) {
        return -1;
    }
    *(s32 *)0xA4080000 = arg0;
    return 0;
}

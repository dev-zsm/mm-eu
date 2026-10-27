// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern u32 D_801EFA00[];
u32 func_8010033C(u32 arg0) {
    if ((arg0 >> 0x1C) == 0) {
        return arg0;
    }
    return D_801EFA00[(arg0 << 4) >> 0x1C] + (arg0 & 0xFFFFFF) + 0x80000000;
}

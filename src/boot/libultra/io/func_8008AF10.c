// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 osVirtualToPhysical(s32 a0);
extern void func_8008A780(s32 a0, s32 a1, s32 a2);
extern void osInvalDCache(s32 a0, s32 a1);

s32 __osSiRawStartDma(s32 arg0, s32 arg1) {
    if (*(s32 *)0xA4800018 & 3) {
        return -1;
    }
    if (arg0 == 1) {
        func_8008A780(arg1, 0x40, arg0);
    }
    *(s32 *)0xA4800000 = osVirtualToPhysical(arg1);
    if (arg0 == 0) {
        *(s32 *)0xA4800004 = 0x1FC007C0;
    } else {
        *(s32 *)0xA4800010 = 0x1FC007C0;
    }
    if (arg0 == 0) {
        osInvalDCache(arg1, 0x40);
    }
    return 0;
}

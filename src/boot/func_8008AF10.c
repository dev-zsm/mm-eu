// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 func_8008A6E0(s32 a0);
extern void func_8008A780(s32 a0, s32 a1, s32 a2);
extern void func_8008F490(s32 a0, s32 a1);

s32 func_8008AF10(s32 arg0, s32 arg1) {
    if (*(s32 *)0xA4800018 & 3) {
        return -1;
    }
    if (arg0 == 1) {
        func_8008A780(arg1, 0x40, arg0);
    }
    *(s32 *)0xA4800000 = func_8008A6E0(arg1);
    if (arg0 == 0) {
        *(s32 *)0xA4800004 = 0x1FC007C0;
    } else {
        *(s32 *)0xA4800010 = 0x1FC007C0;
    }
    if (arg0 == 0) {
        func_8008F490(arg1, 0x40);
    }
    return 0;
}

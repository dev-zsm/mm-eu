// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct V {
    s32 x;
    s32 y;
    s32 z;
} V;

extern V D_80C0ADC8;
void func_80182B28();

void func_800001B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 pad;
    V sp18;

    sp18 = D_80C0ADC8;
    if (arg1 == 0xE) {
        func_80182B28(&sp18, arg4 + 0x3C);
    }
}

// FLAGS: -g
// COMPILER: ido53
#include "types.h"

extern s8 D_801F48C4;
extern s32 D_801F48CC;

void func_801879D8(s32 arg0) {
    D_801F48CC = ((arg0 << 17) + 0x08000000) | 0xA0000000;
    D_801F48C4 = arg0 + 8;
    return;
}

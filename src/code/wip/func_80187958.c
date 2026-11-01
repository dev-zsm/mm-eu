// FLAGS: -O1 -g3 -mips2
#include "types.h"

extern u8 D_801F48C0[];
extern u8 D_801F48C4;
extern u8 D_801F48C5;
extern u8 D_801F48C6;
extern u8 D_801F48C7;
extern u8 D_801F48C8;
extern u8 D_801F48C9;
extern u32 D_801F48CC;

u8 *func_80187958(u8 arg0, u8 arg1, u8 arg2, u8 arg3, u32 arg4) {
    D_801F48CC = arg4 | 0xA0000000;
    D_801F48C4 = D_801F48C4 + 1;
    D_801F48C5 = arg0;
    D_801F48C8 = arg1;
    D_801F48C6 = arg2;
    D_801F48C7 = arg3;
    D_801F48C9 = 1;
    return D_801F48C0;
}

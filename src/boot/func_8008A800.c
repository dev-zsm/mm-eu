// FLAGS: -O1 -g0
#include "types.h"

extern s8 D_8009D504;
extern s8 D_8009D505;
extern s8 D_8009D506;
extern s8 D_8009D507;
extern s8 D_8009D508;
extern s8 D_8009D57C;
extern s8 D_8009D57D;
extern s8 D_8009D57E;
extern s8 D_8009D57F;
extern s8 D_8009D580;

void func_8008A800(void) {
    D_8009D504 = 7;
    D_8009D505 = *(u32 *)0xA4600014;
    D_8009D508 = *(u32 *)0xA4600018;
    D_8009D506 = *(u32 *)0xA460001C;
    D_8009D507 = *(u32 *)0xA4600020;
    D_8009D57C = 7;
    D_8009D57D = *(u32 *)0xA4600024;
    D_8009D580 = *(u32 *)0xA4600028;
    D_8009D57E = *(u32 *)0xA460002C;
    D_8009D57F = *(u32 *)0xA4600030;
}

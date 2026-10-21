// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_8009D140[];
extern s32 D_8009D150;
extern s32 D_8009D158;
extern s32 D_8009D160;
extern s32 D_8009D168;
extern s32 D_8009D16C;
extern s32 D_8009D170;
extern s32 D_8009D178;

void func_80091460(s32 a0, void *dst, s32 size);
s32 func_8008A6E0(s32 arg0);

void *func_80088720(s32 arg0) {
    s32 temp_a0;

    func_80091460(arg0, D_8009D140, 0x40);
    if (D_8009D150 != 0) {
        D_8009D150 = func_8008A6E0(D_8009D150);
    }
    if (D_8009D158 != 0) {
        D_8009D158 = func_8008A6E0(D_8009D158);
    }
    if (D_8009D160 != 0) {
        D_8009D160 = func_8008A6E0(D_8009D160);
    }
    if (D_8009D168 != 0) {
        D_8009D168 = func_8008A6E0(D_8009D168);
    }
    if (D_8009D16C != 0) {
        D_8009D16C = func_8008A6E0(D_8009D16C);
    }
    if (D_8009D170 != 0) {
        D_8009D170 = func_8008A6E0(D_8009D170);
    }
    temp_a0 = D_8009D178;
    if (temp_a0 != 0) {
        D_8009D178 = func_8008A6E0(temp_a0);
    }
    return D_8009D140;
}

// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s32 D_809EF5B8;
extern s32 D_809EF5BC;
extern s32 D_809EF5C0;

void func_80000020(s32 a0, s32 a1, s32 a2) {
    D_809EF5B8 = a0;
    D_809EF5BC = a1;
    D_809EF5C0 = a2;
}

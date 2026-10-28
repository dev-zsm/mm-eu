// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s32 D_809D96A4;
extern s32 D_809D96A8;
extern s32 D_809D96AC;

void func_80000000(s32 a0, s32 a1, s32 a2) {
    D_809D96A4 = a0;
    D_809D96A8 = a1;
    D_809D96AC = a2;
}

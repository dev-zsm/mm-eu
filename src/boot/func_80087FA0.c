// FLAGS: -O2 -g0
#include "types.h"

extern s32 D_800983BC;

void func_80087FA0(s32 a) {
    *(s32 *)&D_800983BC = a;
}

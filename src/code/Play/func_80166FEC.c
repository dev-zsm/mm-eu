// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s32 D_801E6F00;

s32 Play_ChooseDynamicTransition(void *arg0, s32 arg1) {
    s32 v;

    v = arg1;
    if (arg1 == 0x14) {
        v = 2;
        if (D_801E6F00 == 0) {
            v = 3;
        } else {
            v = 2;
        }
    }
    if (v != arg1) {
        *((s8 *)arg0 + 0x1887F) = v;
    }
    return v;
}

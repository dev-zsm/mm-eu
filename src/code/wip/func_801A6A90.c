#include "types.h"

extern u8 D_801F74C4[];

void func_801A6A90(u16 mask) {
    u8 i;

    for (i = 0; i < 7; i++) {
        if (mask & 1) {
            D_801F74C4[i] = 1;
        } else {
            D_801F74C4[i] = 0;
        }
        mask = (s32)mask >> 1;
    }
}

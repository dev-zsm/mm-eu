#include "types.h"

extern s16 *D_801CEAB8;
extern s8 *D_801CEABC;
extern s16 D_801CE944[];

s16 func_801956D0(s32 value) {
    s32 i;

    for (i = 0; i < 15; i++) {
        if (value < D_801CEAB8[i + 1]) {
            break;
        }
    }
    if (i == 15) {
        return 0;
    }
    return D_801CE944[D_801CEABC[i]];
}

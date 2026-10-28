#include "types.h"

extern u16 D_801EC648;
extern u16 D_801EC64A;
extern u16 D_801EC64C[8];
s32 Cutscene_GetCueChannel(s32 a0, u16 a1) {
    int new_var;
    s32 ret = -1;
    s32 i;
    i = a1;
    if (D_801EC648 == i) {
        ret = 0;
    }
    if (D_801EC64A == a1) {
        ret = 1;
    }
    new_var = 2;
    for (i = new_var; i < 10; i++) {
        if (a1 == D_801EC64C[i - new_var]) {
            ret = i;
        }
    }

    return ret;
}

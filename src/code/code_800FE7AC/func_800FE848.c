// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s32 D_801E6F08;
extern s8 D_801EC6B1;
extern s8 D_801EC7B8;

void func_800FE848(s32 arg0) {
    s8 var_v0;

    switch (D_801E6F08) {                           /* irregular */
    default:
    case 0:
    case 1:
        var_v0 = 0;
        break;
    case 2:
        var_v0 = 3;
        break;
    case 3:
        var_v0 = 4;
        break;
    }
    D_801EC7B8 = var_v0;
    D_801EC6B1 = 1;
}

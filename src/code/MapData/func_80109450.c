// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s16 D_801BEEE0[];

s16 MapData_GetMapGrandScale(s32 arg0) {
    return *(s16 *)((u8 *)D_801BEEE0 + arg0 * 10);
}

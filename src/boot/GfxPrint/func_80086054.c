// FLAGS: -O2 -g0 -mips2
#include "types.h"

void GfxPrint_PrintStringWithSize(s32 a0, u8 *a1, s32 a2, s32 a3);

s32 GfxPrint_Callback(s32 arg0, u8 *arg1, s32 arg2) {
    GfxPrint_PrintStringWithSize(arg0, arg1, 1, arg2);
    return arg0;
}

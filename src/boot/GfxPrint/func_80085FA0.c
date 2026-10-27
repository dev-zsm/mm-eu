// FLAGS: -O2 -g0 -mips2
#include "types.h"

void GfxPrint_PrintChar(s32 a0, u8 a1);

void GfxPrint_PrintStringWithSize(s32 arg0, u8 *arg1, s32 arg2, s32 arg3) {
    s32 var_s1;
    u8 *var_s0;

    var_s0 = arg1;
    var_s1 = arg2 * arg3;
    while (var_s1 != 0) {
        GfxPrint_PrintChar(arg0, *var_s0++);
        var_s1 -= 1;
    }
}

// FLAGS: -O2 -g0 -mips2
#include "types.h"

void GfxPrint_PrintChar(s32 a0, u8 a1);

void GfxPrint_PrintString(s32 arg0, u8 *arg1) {
    while (*arg1 != 0) {
        GfxPrint_PrintChar(arg0, *arg1++);
    }
}

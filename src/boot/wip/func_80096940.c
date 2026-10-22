// FLAGS: -O2 -g3 -mips2
#include "types.h"
s32 __osDisableInt(s32 a0, s32 a1, s32 a2);
void __osRestoreInt(s32 a0);
extern s32 D_80097FD0;
extern s32 D_80097FD4;
void __osSetHWIntrRoutine(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;
    temp_v0 = __osDisableInt(arg0, arg1, arg2);
    *(s32 *)((u8 *)&D_80097FD0 + arg0 * 8) = arg1;
    *(s32 *)((u8 *)&D_80097FD4 + arg0 * 8) = arg2;
    __osRestoreInt(temp_v0);
}

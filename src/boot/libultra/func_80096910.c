// FLAGS: -O1 -g0 -mips2
#include "types.h"
extern s32 D_80097FD0;
extern s32 D_80097FD4;
void __osGetHWIntrRoutine(s32 arg0, s32 *arg1, s32 *arg2) {
    *arg1 = *(s32 *)((u8 *)&D_80097FD0 + arg0 * 8);
    *arg2 = *(s32 *)((u8 *)&D_80097FD4 + arg0 * 8);
}

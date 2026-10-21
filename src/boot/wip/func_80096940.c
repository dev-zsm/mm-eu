// FLAGS: -O2 -g3 -mips2
#include "types.h"
s32 func_80091C00(s32 a0, s32 a1, s32 a2);
void func_80091C70(s32 a0);
extern s32 D_80097FD0;
extern s32 D_80097FD4;
void func_80096940(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;
    temp_v0 = func_80091C00(arg0, arg1, arg2);
    *(s32 *)((u8 *)&D_80097FD0 + arg0 * 8) = arg1;
    *(s32 *)((u8 *)&D_80097FD4 + arg0 * 8) = arg2;
    func_80091C70(temp_v0);
}

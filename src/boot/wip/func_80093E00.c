// FLAGS: -O2 -g0 -mips2
#include "types.h"

s32 func_80091C00(void);
void func_80091C70(s32);
void func_800892E4(void *);

extern void *D_80098010;
extern u8 D_80098008;

void func_80093E00(void) {
    s32 temp_s0;

    temp_s0 = func_80091C00();
    *(s16 *)((u8 *)D_80098010 + 0x10) = 2;
    func_800892E4(&D_80098008);
    func_80091C70(temp_s0);
}

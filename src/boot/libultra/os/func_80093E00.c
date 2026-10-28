// FLAGS: -O1 -g0 -mips2
#include "types.h"

s32 __osDisableInt(void);
void __osRestoreInt(s32);
void func_800892E4(void *);

extern void *D_80098010;
extern u8 D_80098008;

void osYieldThread(void) {
    register s32 temp_s0;

    temp_s0 = __osDisableInt();
    *(s16 *)((u8 *)D_80098010 + 0x10) = 2;
    func_800892E4(&D_80098008);
    __osRestoreInt(temp_s0);
}

// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_8009D2A0[];
extern u8 D_8009D2E0;

void func_80089C90(s32 a0);
void func_8008A240(void);
s32 func_8008AF10(s32 a0, void *a1);
void func_80088070(s32 a0, s32 a1, s32 a2);
void func_80089CD4(void);

s32 func_8008A130(s32 arg0) {
    s32 ret;

    func_80089C90(arg0);
    if (D_8009D2E0 != 1) {
        func_8008A240();
        func_8008AF10(1, D_8009D2A0);
        func_80088070(arg0, 0, 1);
    }
    ret = func_8008AF10(0, D_8009D2A0);
    D_8009D2E0 = 1;
    func_80089CD4();
    return ret;
}

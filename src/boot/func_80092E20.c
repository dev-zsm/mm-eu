// FLAGS: -O2 -g0 -mips2
#include "types.h"
void func_80089C90(s32 a0);
void func_80089CD4(void);
extern u8 D_8009D2E0;
extern u8 D_8009D2E1;
s32 func_80092E20(s32 a0) {
    u8 v = a0;
    func_80089C90(a0);
    v = a0;
    if (v >= 5) {
        D_8009D2E1 = 4;
    } else {
        D_8009D2E1 = v;
    }
    D_8009D2E0 = 0xFE;
    func_80089CD4();
    return 0;
}

// FLAGS: -O1 -g3 -mips2
#include "types.h"

extern s32 D_80098050;
s32 func_80091C00(void);
void func_80091C70(s32);

void func_80090820(s32 arg0) {
    s32 temp_s0;

    temp_s0 = func_80091C00();
    D_80098050 |= arg0;
    func_80091C70(temp_s0);
}

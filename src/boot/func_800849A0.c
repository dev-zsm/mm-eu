// FLAGS: -O1 -g0 -mips2
#include "types.h"

s32 func_80095410(void);
void func_80091440(void);

void func_800849A0(void) {
    s32 sp1C;

    sp1C = func_80095410();
    func_80091440();
}

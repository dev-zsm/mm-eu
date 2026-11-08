// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0105.h"

M2C_UNK func_800B6490();                            /* extern */

void func_80002B2C(Actor *thisx, s32 arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(thisx, s16 *, 0x2EE);
    if (temp_v0 > 0) {
        M2C_FIELD(thisx, s16 *, 0x2EE) = (s16) (temp_v0 - 5);
        if (M2C_FIELD(thisx, s16 *, 0x2EE) <= 0) {
            M2C_FIELD(thisx, s16 *, 0x2EE) = 0;
            func_800B6490();
        }
    }
}

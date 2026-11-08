// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0273.h"

M2C_UNK func_800B6490();                            /* extern */

void func_8000071C(Actor *thisx, s32 arg1) {
    if (M2C_FIELD(thisx, s16 *, 0x150) == 0) {
        func_800B6490();
    }
}

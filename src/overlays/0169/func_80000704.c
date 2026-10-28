// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B701C(s32, u8 *, M2C_UNK);        /* extern */
s32 func_8016A23C(s32);                             /* extern */
extern M2C_UNK D_80937DC0;

void func_80000704(u8 *arg0, s32 arg1) {
    if (func_8016A23C(arg1) == 0) {
        func_800B701C(arg1, arg0, 7);
        M2C_FIELD(arg0, M2C_UNK **, 0x394) = &D_80937DC0;
    }
}

// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800897D0(s32, M2C_UNK);                /* extern */

s32 func_8000013C(s32 arg0) {
    func_800897D0(arg0, 0x120);
    return arg0;
}

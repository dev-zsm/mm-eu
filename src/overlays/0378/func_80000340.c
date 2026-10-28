// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8019FFD8(M2C_UNK);                     /* extern */

void func_80000340(s32 arg0, u8 *arg1) {
    if (M2C_FIELD(arg1, u16 *, 0x1F34) == 0x217) {
        func_8019FFD8(0x2915);
    }
}

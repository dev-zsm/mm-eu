// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8BDC(s32, s32);                    /* extern */
s32 func_8082D77C(s32, M2C_UNK);                    /* extern */

void func_8000072C(s32 arg0) {
    func_800B8BDC(arg0, func_8082D77C(arg0, 0x820) & 0xFFFF);
}

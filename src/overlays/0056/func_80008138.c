// FLAGS: -O1 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFF1C(s32, s16);                    /* extern */

void func_80008138(u8 *arg0, s32 arg1) {
    func_800FFF1C(arg1, M2C_FIELD(arg0, s16 *, 0xBE));
}

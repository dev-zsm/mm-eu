// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80115C10(s16, u8 *);                 /* extern */

void func_80000E34(u8 *arg0, M2C_UNK arg1) {
    func_80115C10((s16) (M2C_FIELD(arg0, s32 *, 0x16978) * -1), arg0);
}

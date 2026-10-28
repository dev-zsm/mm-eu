// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80112D7C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80115C10(s16);                         /* extern */

void func_80000CE8(u8 *arg0, M2C_UNK arg1) {
    func_80112D7C(arg0, 0x12);
    func_80115C10((s16) (M2C_FIELD(arg0, s32 *, 0x16978) * -1));
}

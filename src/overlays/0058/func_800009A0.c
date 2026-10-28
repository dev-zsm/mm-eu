// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80115C10(s16);                         /* extern */
M2C_UNK func_80115C38(M2C_UNK, s16, u8 *);        /* extern */

void func_800009A0(u8 *arg0, u8 *arg1) {
    func_80115C38(1, M2C_FIELD(arg1, s16 *, 0x1C2), arg1);
    func_80115C10((s16) (M2C_FIELD(arg0, s32 *, 0x16978) * -1));
}

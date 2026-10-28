// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80A02A48(u8 *);                      /* extern */
M2C_UNK func_80A02B40();                            /* extern */

void func_80000434(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 0x4A8) = (s32) (M2C_FIELD(arg0, s32 *, 0x4A8) ^ 1);
    func_80A02B40();
    func_80A02A48(arg0);
}

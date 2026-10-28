// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80B06BD4(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80B06D2C(u8 *);                      /* extern */
M2C_UNK func_80B071F0(u8 *);                      /* extern */

void func_8000092C(u8 *arg0, M2C_UNK arg1) {
    if ((M2C_FIELD(arg0, u8 *, 0x15E) & 2) && (M2C_FIELD(arg0, s32 *, 0x120) == M2C_FIELD(arg0, s32 *, 0x158))) {
        func_80B06BD4(arg0, 1);
        func_80B06D2C(arg0);
        return;
    }
    if (M2C_FIELD(arg0, u16 *, 0x90) & 1) {
        func_80B06BD4(arg0, 2);
        func_800B8C4C(arg0, 0x2947);
        func_80B071F0(arg0);
    }
}

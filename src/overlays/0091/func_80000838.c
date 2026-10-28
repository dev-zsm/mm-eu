// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEE3C(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_808AF67C(u8 *);                      /* extern */
M2C_UNK func_808AF8E8(u8 *);                      /* extern */

void func_80000838(u8 *arg0) {
    func_808AF8E8(arg0);
    if (!(M2C_FIELD(arg0, u16 *, 0x90) & 1)) {
        func_800FEE3C(arg0 + 0x24, M2C_FIELD(arg0, s32 *, 8), 0x40000000);
        func_800FEE3C(arg0 + 0x2C, M2C_FIELD(arg0, s32 *, 0x10), 0x40000000);
    }
    if (M2C_FIELD(arg0, s16 *, 0x32) == M2C_FIELD(arg0, s16 *, 0x16)) {
        func_808AF67C(arg0);
    }
}

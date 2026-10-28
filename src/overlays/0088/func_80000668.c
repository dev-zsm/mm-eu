// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80115540(s32, M2C_UNK);                /* extern */
M2C_UNK func_80151E7C(s32, M2C_UNK);                /* extern */
M2C_UNK func_808A77C0(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_808A88D4;

void func_80000668(s32 arg0, u8 *arg1) {
    func_808A77C0(arg1, &D_808A88D4);
    func_80151E7C(arg0, 0x640);
    func_80115540(arg0, 6);
    M2C_FIELD(arg1, s32 *, 0x2A4) = 1;
    M2C_FIELD(arg1, s32 *, 0x26C) = 1;
}

// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BB80C(s32, u8 *);                 /* extern */
M2C_UNK func_800F0308(s32, u8 *, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK D_80B9C1A8;

void func_80000BC8(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80B9C1A8;
    if (M2C_FIELD(arg0, s8 *, 0xB7) <= 0) {
        func_800BB80C(arg1, arg0);
        func_800F0308(arg1, arg0 + 0x24, 0x1E, 0x3A12);
        return;
    }
    func_800B8C4C(arg0, 0x3A11);
}

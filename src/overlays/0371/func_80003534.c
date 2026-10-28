// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80136ED0(s32, s32, M2C_UNK *, M2C_UNK *, s32, s32, s32); /* extern */
extern M2C_UNK D_600FD34;
extern M2C_UNK D_600FEF0;
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80A74960;

void func_80003534(u8 *arg0, s32 arg1) {
    func_80136ED0(arg1, arg0 + 0x14C, &D_600FEF0, &D_600FD34, 0, 0, 0);
    if (!(M2C_FIELD(&D_801E6EF0, u8 *, 0xF04) & 8) && !(M2C_FIELD(&D_801E6EF0, u8 *, 0xF4C) & 0x40) && (M2C_FIELD(&D_801E6EF0, s32 *, 0x18) >= 2)) {
        M2C_FIELD(arg0, M2C_UNK **, 0x13C) = NULL;
        return;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80A74960;
}

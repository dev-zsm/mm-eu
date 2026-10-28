// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137934(u8 *, M2C_UNK *, s32, u8 *); /* extern */
extern M2C_UNK D_6014110;
extern M2C_UNK D_809B77D0;

void func_80002514(u8 *arg0, M2C_UNK arg1, u8 arg2) {
    M2C_FIELD(arg0, u8 *, 0x14C) = arg2;
    func_80137934(arg0 + 0x164, &D_6014110, M2C_FIELD(arg0, s32 *, 0x158), arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x464) = &D_809B77D0;
    M2C_FIELD(arg0, s16 *, 0x14E) = 5;
}

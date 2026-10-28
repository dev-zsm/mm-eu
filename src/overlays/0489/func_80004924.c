// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137934(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6002A8C;
extern M2C_UNK D_80B2D054;

void func_80004924(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x2F0) = 0x28;
    func_80137934(arg0 + 0x144, &D_6002A8C, 0xC1200000, arg0);
    M2C_FIELD(arg0, s32 *, 0x13C) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x2EC) = &D_80B2D054;
}

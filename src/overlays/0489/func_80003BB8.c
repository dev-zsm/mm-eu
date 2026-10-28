// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6001D80;
extern M2C_UNK D_80B2C330;
extern M2C_UNK D_80B32844;

void func_80003BB8(u8 *arg0) {
    func_80137934(arg0 + 0x144, &D_6001D80, 0xC0C00000, arg0);
    M2C_FIELD(arg0, u8 *, 0x2B0) = (u8) (M2C_FIELD(arg0, u8 *, 0x2B0) & 0xFFFE);
    M2C_FIELD(arg0, u8 *, 0x2B1) = (u8) (M2C_FIELD(arg0, u8 *, 0x2B1) & 0xFFFE);
    M2C_FIELD(arg0, u8 *, 0x2B2) = (u8) (M2C_FIELD(arg0, u8 *, 0x2B2) & 0xFFFE);
    M2C_FIELD(arg0, s8 *, 0x389) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80B32844;
    M2C_FIELD(arg0, s8 *, 0x38B) = 1;
    M2C_FIELD(arg0, s8 *, 0x38C) = 0;
    M2C_FIELD(arg0, s8 *, 0x38D) = 0;
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x80000000);
    M2C_FIELD(arg0, M2C_UNK **, 0x2EC) = &D_80B2C330;
}

// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6000D40;
extern M2C_UNK D_80B00020;

void func_80000ED0(u8 *arg0) {
    func_80137934(arg0 + 0x144, &D_6000D40, 0xC0400000, arg0);
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) (M2C_FIELD(arg0, s16 *, 0x92) + 0x8000);
    if (M2C_FIELD(arg0, u8 *, 0x18C) != 0) {
        M2C_FIELD(arg0, s8 *, 0x320) = 3;
        M2C_FIELD(arg0, u8 *, 0x31D) = (u8) (M2C_FIELD(arg0, u8 *, 0x31D) & 0xFFFB);
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80B00020;
}

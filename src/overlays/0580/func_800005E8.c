// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E26E8(s32, s32, u8 *, u8 *);    /* extern */
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80BBCDE0;

void func_800005E8(u8 *arg0, s32 arg1) {
    if (M2C_FIELD(&D_801E6EF0, u8 *, 0xF32) & 0x80) {
        M2C_FIELD(arg0, M2C_UNK **, 0x1AC) = &D_80BBCDE0;
        M2C_FIELD(&D_801E6EF0, u8 *, 0xF51) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF51) | 0x80);
    }
    func_800E26E8(arg1, arg1 + 0x18884, arg0 + 0x15C, arg0);
}

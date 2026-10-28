// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80AE1690(u8 *);                      /* extern */
s32 func_80AE1954(u8 *, s32);                     /* extern */
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80AE1904;
extern M2C_UNK D_80AE1AF8;

void func_80000134(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x144) = 0x17;
    func_80AE1690(arg0);
    func_800B6564(arg0, 0x3F800000);
    if ((M2C_FIELD(arg0, s16 *, 0x1C) & 0xF) == 1) {
        M2C_FIELD(arg0, s32 *, 0x13C) = 0;
        M2C_FIELD(arg0, M2C_UNK **, 0x150) = &D_80AE1904;
        return;
    }
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & 0xFDFFFFFF);
    if (func_80AE1954(arg0, arg1) != 0) {
        M2C_FIELD(&D_801E6EF0, u8 *, 0x100F) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0x100F) | 2);
    } else {
        M2C_FIELD(&D_801E6EF0, u8 *, 0x100F) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0x100F) & 0xFD);
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x150) = &D_80AE1AF8;
    M2C_FIELD(&D_801E6EF0, u8 *, 0x100F) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0x100F) & 0xFB);
}

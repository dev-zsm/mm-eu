// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_600319C;
extern M2C_UNK D_80AEE5EC;

void func_800045B0(u8 *arg0, u8 *arg1) {
    u8 *sp1C;

    sp1C = M2C_FIELD(arg1, u8 **, 0x1CCC);
    func_80137828(arg0 + 0x144, &D_600319C, 0xC1200000, arg0);
    M2C_FIELD(sp1C, u8 **, 0x120) = arg0;
    M2C_FIELD(arg0, u8 *, 0x494) = (u8) (M2C_FIELD(arg0, u8 *, 0x494) & 0xFFFE);
    M2C_FIELD(arg0, u8 *, 0x496) = (u8) (M2C_FIELD(arg0, u8 *, 0x496) & 0xFFFE);
    M2C_FIELD(arg0, s16 *, 0x19C) = 0xA;
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80AEE5EC;
}

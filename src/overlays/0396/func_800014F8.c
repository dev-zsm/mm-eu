// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8010E890(M2C_UNK, M2C_UNK, u8 *);    /* extern */
M2C_UNK func_801129F8(u8 *);                      /* extern */
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80AA3F48;

void func_800014F8(u8 *arg0, u8 *arg1) {
    u8 *sp1C;

    sp1C = M2C_FIELD(arg1, u8 **, 0x1CCC);
    M2C_FIELD(arg1, s8 *, 0x16C68) = 1;
    func_8010E890(4, 0, arg1);
    M2C_FIELD(&D_801E6EF0, u8 *, 0xF00) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF00) | 1);
    func_801129F8(arg1);
    M2C_FIELD(sp1C, s32 *, 0xA6C) = (s32) (M2C_FIELD(sp1C, s32 *, 0xA6C) | 0x20);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80AA3F48;
}

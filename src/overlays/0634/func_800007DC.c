// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8010E890(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_801129F8(u8 *);                      /* extern */
M2C_UNK func_801A3A68(M2C_UNK);                     /* extern */
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80BF8F2C;

void func_800007DC(u8 *arg0, u8 *arg1) {
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    M2C_FIELD(temp_v0, s32 *, 0xA6C) = (s32) (M2C_FIELD(temp_v0, s32 *, 0xA6C) | 0x20);
    func_801A3A68(0x25);
    M2C_FIELD(arg1, s8 *, 0x16C68) = 1;
    func_801129F8(arg1);
    M2C_FIELD(&D_801E6EF0, u8 *, 0xF52) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF52) | 0x20);
    func_8010E890(4, 0x78);
    M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80BF8F2C;
}

// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80938630(u8 *);                      /* extern */
M2C_UNK func_80938898();                            /* extern */
extern M2C_UNK D_80938A8C;

void func_80000484(u8 *arg0, u8 *arg1) {
    s16 temp_v1;
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    M2C_FIELD(temp_v0, s16 *, 0xBE) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    temp_v1 = M2C_FIELD(temp_v0, s16 *, 0xBE);
    M2C_FIELD(temp_v0, s16 *, 0x32) = temp_v1;
    M2C_FIELD(temp_v0, s16 *, 0xAD4) = temp_v1;
    M2C_FIELD(temp_v0, s16 *, 0x4A) = temp_v1;
    M2C_FIELD(arg0, u16 *, 0x160) = (u16) (M2C_FIELD(arg0, u16 *, 0x160) | 0x10);
    func_80938898();
    if (M2C_FIELD(arg0, s32 *, 0x164) != 0) {
        func_80938630(arg0);
    }
    M2C_FIELD(arg0, s16 *, 0x16E) = -1;
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80938A8C;
}

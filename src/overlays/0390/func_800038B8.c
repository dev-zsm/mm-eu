// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_80A99BB8(u8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK D_80A9D25C;

void func_800038B8(u8 *arg0, M2C_UNK arg1) {
    s32 temp_v0;

    func_80137070(arg0 + 0x148);
    func_80137070(arg0 + 0x2A0);
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x3C8);
    if (temp_v0 > 0) {
        M2C_FIELD(arg0, s32 *, 0x3C8) = (s32) (temp_v0 - 1);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x3C8) = 0x3C;
    M2C_FIELD(arg0, M2C_UNK **, 0x3E8) = &D_80A9D25C;
    func_80A99BB8(arg0, 1, 2, 0xC0A00000);
    M2C_FIELD(arg0, s32 *, 0x3E0) = 3;
}

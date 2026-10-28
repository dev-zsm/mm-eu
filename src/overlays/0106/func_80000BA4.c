// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BE0C0(s32, u8 *, u8 *, M2C_UNK); /* extern */
M2C_UNK func_808C99D8(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_808CA3A8;
extern s32 D_808CB928;

void func_80000BA4(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x1C) = 0;
    M2C_FIELD(arg0, f32 *, 0x70) = 8.0f;
    func_800BE0C0(M2C_FIELD(arg0, s32 *, 0x120) + 0x24, arg0 + 0x24, arg0 + 0x150, 0);
    if (D_808CB928 != 0) {
        M2C_FIELD(arg0, s16 *, 0x14A) = (s16) D_808CB928;
    } else {
        M2C_FIELD(arg0, s16 *, 0x14A) = 0xC8;
    }
    func_808C99D8(arg0, 0);
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_808CA3A8;
}

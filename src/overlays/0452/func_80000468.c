// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BD9E0(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_80AE397C;
extern M2C_UNK D_80AE3AAC;
extern M2C_UNK D_80AE5F30;
extern f32 D_80AE61A0;

void func_80000468(u8 *arg0) {
    func_800BD9E0(arg0 + 0x190, &D_80AE5F30, 0xA, arg0);
    M2C_FIELD(arg0, f32 *, 0x70) = (f32) D_80AE61A0;
    if (&D_80AE397C == M2C_FIELD(arg0, M2C_UNK **, 0x1D4)) {
        M2C_FIELD(arg0, s16 *, 0x3EA) = 0x50;
    } else {
        M2C_FIELD(arg0, s16 *, 0x3EA) = 0x14;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80AE3AAC;
}

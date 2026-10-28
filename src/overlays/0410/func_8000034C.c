// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s32 func_800FEE3C(u8 *, f32, s32);                /* extern */
extern M2C_UNK D_80AAFC20;

void func_8000034C(u8 *arg0, M2C_UNK arg1) {
    func_800FEE3C(arg0 + 0x68, 15.0f, 0x40400000);
    if (func_800FEE3C(arg0 + 0x28, M2C_FIELD(arg0, f32 *, 0xC) + 120.0f, M2C_FIELD(arg0, s32 *, 0x68)) != 0) {
        M2C_FIELD(arg0, s32 *, 0x164) = (s32) (M2C_FIELD(arg0, s32 *, 0x164) + 1);
    }
    if (M2C_FIELD(arg0, s32 *, 0x164) >= 0xA) {
        func_800B8C4C(arg0, 0x281C);
        M2C_FIELD(arg0, M2C_UNK **, 0x160) = &D_80AAFC20;
    }
}

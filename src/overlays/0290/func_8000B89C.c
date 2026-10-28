// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137934(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_600AE40;
extern M2C_UNK D_809E4FA4;

void func_8000B89C(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_809E4FA4;
    func_80137934(arg0 + 0x190, &D_600AE40, 0xC1200000, arg0);
    M2C_FIELD(arg0, s16 *, 0x150) = 0x64;
    M2C_FIELD(arg0, f32 *, 0x170) = 0.0f;
}

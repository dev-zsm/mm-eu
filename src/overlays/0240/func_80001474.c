// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BD9E0(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_8097A9C4;
extern M2C_UNK D_8097C070;

void func_80001474(u8 *arg0) {
    func_800BD9E0(arg0 + 0x144, &D_8097C070, 2, arg0);
    M2C_FIELD(arg0, u8 *, 0x198) = (u8) (M2C_FIELD(arg0, u8 *, 0x198) & 0xFFFB);
    M2C_FIELD(arg0, s16 *, 0x3DE) = 3;
    M2C_FIELD(arg0, M2C_UNK **, 0x228) = &D_8097A9C4;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}

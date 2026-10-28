// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80A33018();                            /* extern */

void func_8000073C(u8 *arg0, M2C_UNK arg1) {
    u8 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 *, 0x18C);
    if (temp_v0 & 2) {
        M2C_FIELD(arg0, u8 *, 0x18C) = (u8) (temp_v0 & 0xFFFC);
    }
    if ((M2C_FIELD(arg0, f32 *, 0x68) < 0.0f) && (M2C_FIELD(arg0, u16 *, 0x90) & 1)) {
        M2C_FIELD(arg0, s8 *, 0x149) = 2;
        M2C_FIELD(arg0, u8 *, 0x18C) = (u8) (M2C_FIELD(arg0, u8 *, 0x18C) & 0xFFFE);
        func_80A33018();
    }
}

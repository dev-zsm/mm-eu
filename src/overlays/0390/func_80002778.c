// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80A9C084();                            /* extern */
extern M2C_UNK D_801E6EF0;

void func_80002778(u8 *arg0, u8 *arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x92);
    M2C_FIELD(arg0, s16 *, 0xBE) = temp_v0;
    M2C_FIELD(arg0, s16 *, 0x32) = temp_v0;
    if ((M2C_FIELD(arg0, f32 *, 0x98) < 200.0f) && ((M2C_FIELD(&D_801E6EF0, u8 *, 0xF0A) & 1) || (M2C_FIELD(&D_801E6EF0, u8 *, 0xF50) & 1)) && (M2C_FIELD(arg1, u8 *, 0x18B48) != 0)) {
        func_80A9C084();
    }
}

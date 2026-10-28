// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80137070(u8 *);                          /* extern */
M2C_UNK func_80137788(u8 *, s32, M2C_UNK, M2C_UNK, f32, s32, f32); /* extern */

void func_80001EF8(u8 *arg0) {
    u8 *temp_a0;

    if (func_80137070(M2C_FIELD(arg0, u8 **, 0x3D4)) != 0) {
        temp_a0 = M2C_FIELD(arg0, u8 **, 0x3D4);
        func_80137788(temp_a0, M2C_FIELD(temp_a0, s32 *, 8), 0x3F800000, 0x41900000, 35.0f, 2, 0.0f);
        M2C_FIELD(arg0, u16 *, 0x3E8) = (u16) (M2C_FIELD(arg0, u16 *, 0x3E8) | 1);
        return;
    }
    M2C_FIELD(arg0, u16 *, 0x3E8) = (u16) (M2C_FIELD(arg0, u16 *, 0x3E8) & 0xFFFE);
}

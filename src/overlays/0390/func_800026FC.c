// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80A9C084();                            /* extern */
extern M2C_UNK D_801E6EF0;

void func_800026FC(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x92);
    M2C_FIELD(arg0, s16 *, 0xBE) = temp_v0;
    M2C_FIELD(arg0, s16 *, 0x32) = temp_v0;
    if (((M2C_FIELD(arg0, f32 *, 0x98) < 200.0f) && (M2C_FIELD(&D_801E6EF0, u8 *, 0xF04) & 8)) || (M2C_FIELD(&D_801E6EF0, u8 *, 0x100E) & 0x40)) {
        M2C_FIELD(&D_801E6EF0, u8 *, 0x100E) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0x100E) | 0x40);
        func_80A9C084();
    }
}

// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80BC1AD8(u8 *, u8 *, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80BC1DEC(u8 *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK D_80BC20F0;

void func_80001220(u8 *arg0, u8 *arg1) {
    s16 temp_v0;

    M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
    if (M2C_FIELD(arg0, f32 *, 0x98) > 440.0f) {
        M2C_FIELD(arg0, M2C_UNK **, 0x618) = &D_80BC20F0;
        func_80BC1DEC(arg0, 2, 2);
    } else if (M2C_FIELD(arg0, u16 *, 0x2CA) & 2) {
        func_80BC1DEC(arg0, 0, 0);
    }
    if (!(M2C_FIELD(arg1, s32 *, 0x18840) & 7)) {
        func_80BC1AD8(arg0, arg0 + 0x2D0, 0x3E4CCCCD, 0x3F800000, 0xC8);
    }
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x2CE);
    if (temp_v0 < 0xF5) {
        M2C_FIELD(arg0, s16 *, 0x2CE) = (s16) (temp_v0 + 0xA);
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x2CE) = 0xFF;
}

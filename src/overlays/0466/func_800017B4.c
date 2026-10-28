// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B043E4;

void func_800017B4(u8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x3F4);
    if (((temp_v0 == 0xB) || (temp_v0 == 0xA)) && (M2C_FIELD(arg0, s16 *, 0x3F2) == 0)) {
        M2C_FIELD(arg0, s16 *, 0x3F2) = 0;
        M2C_FIELD(arg0, s16 *, 0x3F4) = 0;
    }
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    M2C_FIELD(arg0, s16 *, 0x2C8) = 6;
    M2C_FIELD(arg0, M2C_UNK **, 0x2C0) = &D_80B043E4;
}

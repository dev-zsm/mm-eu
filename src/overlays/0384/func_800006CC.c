// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A91A04;

void func_800006CC(u8 *arg0, M2C_UNK arg1) {
    u32 temp_v0;
    u32 temp_v0_2;
    u32 temp_v0_3;

    temp_v0 = M2C_FIELD(arg0, u32 *, 0x19C);
    if (temp_v0 < 0xF7U) {
        M2C_FIELD(arg0, u32 *, 0x19C) = (u32) (temp_v0 + 8);
    }
    temp_v0_2 = M2C_FIELD(arg0, u32 *, 0x1A0);
    if (temp_v0_2 < 0xF7U) {
        M2C_FIELD(arg0, u32 *, 0x1A0) = (u32) (temp_v0_2 + 8);
    }
    temp_v0_3 = M2C_FIELD(arg0, u32 *, 0x1A4);
    if (temp_v0_3 < 0xF7U) {
        M2C_FIELD(arg0, u32 *, 0x1A4) = (u32) (temp_v0_3 + 8);
        return;
    }
    M2C_FIELD(arg0, u32 *, 0x19C) = 0xFFU;
    M2C_FIELD(arg0, u32 *, 0x1A0) = 0xFFU;
    M2C_FIELD(arg0, u32 *, 0x1A4) = 0xFFU;
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80A91A04;
}

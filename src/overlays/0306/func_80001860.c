// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A0DAF0;
extern M2C_UNK D_80A0E39C;

void func_80001860(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80A0E39C;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    M2C_FIELD(arg0, s16 *, 0xBC) = 0;
    M2C_FIELD(arg0, s16 *, 0xC0) = 0;
    M2C_FIELD(arg0, f32 *, 0x2A8) = 0.0f;
    M2C_FIELD(arg0, u8 *, 0x2C1) = (u8) (M2C_FIELD(arg0, u8 *, 0x2C1) | 1);
    M2C_FIELD(arg0, M2C_UNK **, 0x298) = &D_80A0DAF0;
}

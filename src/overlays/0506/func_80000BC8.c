// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B56208;

void func_80000BC8(u8 *arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x2E0);
    M2C_FIELD(arg0, u8 *, 0x402) = (u8) (M2C_FIELD(arg0, u8 *, 0x402) | 0x40);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, s32 *, 0x2E4) = (s32) (temp_v0 - 1);
    } else {
        M2C_FIELD(arg0, s32 *, 0x2E4) = (s32) (M2C_FIELD(arg0, s32 *, 0x2E8) - 1);
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x228) = &D_80B56208;
}

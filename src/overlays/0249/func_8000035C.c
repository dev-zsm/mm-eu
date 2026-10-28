// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_8000035C(u8 *arg0, u8 *arg1) {
    s32 temp_v0;

    M2C_FIELD(arg0, s32 *, 0x300) = 0;
    temp_v0 = (s32) (M2C_FIELD(arg0, s16 *, 0x1C) & 0xFC00) >> 0xA;
    if (temp_v0 != 0x3F) {
        M2C_FIELD(arg0, s32 *, 0x2FC) = (s32) (M2C_FIELD(arg1, s32 *, 0x18864) + (temp_v0 * 8));
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x2FC) = 0;
}

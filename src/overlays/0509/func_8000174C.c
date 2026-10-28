// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_8000174C(s32 arg0, u8 *arg1) {
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    M2C_FIELD(temp_v0, s16 *, 0x48) = 0;
    M2C_FIELD(temp_v0, s16 *, 0x4C) = 0;
    M2C_FIELD(temp_v0, s16 *, 0x4A) = (s16) M2C_FIELD(temp_v0, s16 *, 0xBE);
    M2C_FIELD(temp_v0, s16 *, 0xAAC) = 0;
    M2C_FIELD(temp_v0, s16 *, 0xAAE) = 0;
    M2C_FIELD(temp_v0, s16 *, 0xAB0) = 0;
    M2C_FIELD(temp_v0, s16 *, 0xAB2) = 0;
    M2C_FIELD(temp_v0, s16 *, 0xAB4) = 0;
    M2C_FIELD(temp_v0, s16 *, 0xAB6) = 0;
    M2C_FIELD(temp_v0, s16 *, 0xAD4) = (s16) M2C_FIELD(temp_v0, s16 *, 0x4A);
}

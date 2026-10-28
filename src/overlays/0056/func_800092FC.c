// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_800092FC(u8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x4A);
    M2C_FIELD(arg0, s16 *, 0x48) = 0;
    M2C_FIELD(arg0, s16 *, 0x4C) = 0;
    M2C_FIELD(arg0, s16 *, 0xAAC) = 0;
    M2C_FIELD(arg0, s16 *, 0xAAE) = 0;
    M2C_FIELD(arg0, s16 *, 0xAB0) = 0;
    M2C_FIELD(arg0, s16 *, 0xAB2) = 0;
    M2C_FIELD(arg0, s16 *, 0xAB4) = 0;
    M2C_FIELD(arg0, s16 *, 0xAB6) = 0;
    M2C_FIELD(arg0, s16 *, 0xBE) = temp_v0;
    M2C_FIELD(arg0, s16 *, 0xAD4) = temp_v0;
}

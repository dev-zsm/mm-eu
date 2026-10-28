// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80001718(u8 *arg0, u8 *arg1, s16 arg2) {
    s16 temp_v1;
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    temp_v1 = M2C_FIELD(arg0, s16 *, 0xBE) + arg2;
    M2C_FIELD(temp_v0, s16 *, 0xAD4) = temp_v1;
    M2C_FIELD(temp_v0, s16 *, 0x32) = temp_v1;
    M2C_FIELD(temp_v0, s16 *, 0xBE) = temp_v1;
}

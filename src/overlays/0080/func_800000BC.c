// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800000BC(u8 *arg0) {
    u8 *temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8 **, 0x164);
    M2C_FIELD(temp_v1, s32 *, 0) = 8;
    M2C_FIELD(temp_v1, s8 *, 4) = 0;
    M2C_FIELD(temp_v1, s8 *, 5) = 4;
    M2C_FIELD(temp_v1, s8 *, 0x15) = 1;
    M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
    return 6;
}

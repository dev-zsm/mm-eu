// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80000000(u8 *arg0) {
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 **, 0x178);
    if (M2C_FIELD(temp_v0, u8 *, 0x16) & 2) {
        return 0;
    }
    if (M2C_FIELD(temp_v0, u8 *, 0x56) & 2) {
        return 1;
    }
    if (M2C_FIELD(temp_v0, u8 *, 0x96) & 2) {
        return 2;
    }
    if (M2C_FIELD(temp_v0, u8 *, 0xD6) & 2) {
        return 3;
    }
    return -1;
}

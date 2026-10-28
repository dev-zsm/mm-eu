// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

u8 func_800011A4(u8 *arg0) {
    u8 temp_v0;
    u8 temp_v1;

    temp_v0 = M2C_FIELD(arg0, u8 *, 0xB8);
    temp_v1 = M2C_FIELD(arg0, u8 *, 0xB7);
    if ((s32) temp_v0 < (s32) temp_v1) {
        M2C_FIELD(arg0, u8 *, 0xB7) = (u8) (temp_v1 - temp_v0);
    } else {
        M2C_FIELD(arg0, u8 *, 0xB7) = 0U;
    }
    return M2C_FIELD(arg0, u8 *, 0xB7);
}

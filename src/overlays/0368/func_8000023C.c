// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_8000023C(u8 *arg0) {
    u8 *temp_v0;

    if (M2C_FIELD(arg0, u8 *, 0x157) & 1) {
        return 1;
    }
    if (M2C_FIELD(arg0, u8 *, 0x156) & 2) {
        temp_v0 = M2C_FIELD(arg0, u8 **, 0x150);
        if ((M2C_FIELD(temp_v0, s16 *, 0) == 0x185) && (M2C_FIELD(arg0, s8 *, 3) == M2C_FIELD(temp_v0, s8 *, 3))) {
            return 1;
        }
    }
    return 0;
}

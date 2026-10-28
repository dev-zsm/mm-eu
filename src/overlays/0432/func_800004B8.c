// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800004B8(u8 *arg0) {
    if (M2C_FIELD(arg0, s16 *, 0x384) != -1) {
        return 0;
    }
    if (M2C_FIELD(arg0, s16 *, 0x386) != -1) {
        return 1;
    }
    if (M2C_FIELD(arg0, s16 *, 0x388) != -1) {
        return 2;
    }
    return 0xFF;
}

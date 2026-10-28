// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern s32 D_801E6F08;

s32 func_800002EC(u8 *arg0) {
    if ((((s32) D_801E6F08 % 5) == 2) && (M2C_FIELD(arg0, s16 *, 0xA4) == 0x43)) {
        return 1;
    }
    return 0;
}

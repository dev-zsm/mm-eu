// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80114D8C();                                /* extern */
extern s16 D_801E6F2A;

s32 func_8000071C(u8 *arg0) {
    if (func_80114D8C() == 0) {
        return 2;
    }
    if (D_801E6F2A < 0x28) {
        return 1;
    }
    M2C_FIELD(arg0, s16 *, 0x364) = -0x28;
    M2C_FIELD(arg0, s8 *, 0x366) = 0x14;
    return 3;
}

// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s8 func_8013DCD4(M2C_UNK, s32);                     /* extern */
extern M2C_UNK D_80C016F8;

void func_80000880(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 0x2AC) = func_8013DCD4(0x1A, arg1);
    M2C_FIELD(arg0, s8 *, 0x2AD) = func_8013DCD4(0x16, arg1);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80C016F8;
}

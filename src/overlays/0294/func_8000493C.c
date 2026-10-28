// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s8 func_8013DCD4(M2C_UNK, s32);                     /* extern */
extern M2C_UNK D_809F94C8;

void func_8000493C(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 0x288) = func_8013DCD4(0x1D8, arg1);
    M2C_FIELD(arg0, s8 *, 0x289) = func_8013DCD4(0x1F7, arg1);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_809F94C8;
}

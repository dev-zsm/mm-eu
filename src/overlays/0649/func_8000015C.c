// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s8 func_8013DCD4(M2C_UNK);                          /* extern */
extern M2C_UNK D_80C03074;

void func_8000015C(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0x208) = func_8013DCD4(0x16);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80C03074;
}

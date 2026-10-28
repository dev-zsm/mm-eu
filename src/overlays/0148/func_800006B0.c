// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_809136CC;

void func_800006B0(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_809136CC;
    M2C_FIELD(arg0, s16 *, 0x222) = 3;
}

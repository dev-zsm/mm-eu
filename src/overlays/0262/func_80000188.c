// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80991300();                                /* extern */
extern M2C_UNK D_809913CC;
extern M2C_UNK D_80991868;

void func_80000188(u8 *arg0) {
    if ((M2C_FIELD(arg0, s16 *, 0x14C) != 0) || (func_80991300() != 0)) {
        M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80991868;
        M2C_FIELD(arg0, s16 *, 0x14A) = 5;
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_809913CC;
    }
}

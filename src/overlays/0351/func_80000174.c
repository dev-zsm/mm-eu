// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80A45984();                                /* extern */
extern M2C_UNK D_80A45A3C;
extern M2C_UNK D_80A45DA0;

void func_80000174(u8 *arg0) {
    if (func_80A45984() != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80A45DA0;
        M2C_FIELD(arg0, s16 *, 0x148) = 5;
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80A45A3C;
    }
}

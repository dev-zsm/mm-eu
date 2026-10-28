// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800F1E2C();                                /* extern */
s32 func_80B166D8(s32);                             /* extern */
M2C_UNK func_80B16700(s32, s32);                    /* extern */
extern M2C_UNK D_80B16FEC;

void func_80000C40(u8 *arg0, s32 arg1) {
    if (func_800F1E2C() != M2C_FIELD(arg0, s8 *, 0x38)) {
        M2C_FIELD(arg0, M2C_UNK **, 0x1F8) = &D_80B16FEC;
        func_80B16700(arg1, func_80B166D8(arg1) + 1);
    }
}

// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B2FA6C();                            /* extern */
extern u8 D_801E7DFE;
extern M2C_UNK D_80B33054;

void func_80007340(u8 *arg0, M2C_UNK arg1) {
    if (D_801E7DFE & 1) {
        M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80B33054;
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 9);
        func_80B2FA6C();
    }
}

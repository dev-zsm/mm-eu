// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B2F344();                            /* extern */
extern u16 D_801E6EFC;
extern M2C_UNK D_80B2F90C;
extern M2C_UNK D_80B33054;

void func_800071DC(u8 *arg0, M2C_UNK arg1) {
    if (((s32) D_801E6EFC < 0x4000) && ((s32) D_801E6EFC >= 0x1800)) {
        M2C_FIELD(arg0, M2C_UNK **, 0x138) = &D_80B2F90C;
        M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80B33054;
        func_80B2F344();
    }
}

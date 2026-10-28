// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B313F8();                            /* extern */
extern u16 D_801E6EFC;
extern M2C_UNK D_80B31D84;
extern M2C_UNK D_80B33054;

void func_8000964C(u8 *arg0, M2C_UNK arg1) {
    if (((s32) D_801E6EFC >= 0xD555) && ((s32) D_801E6EFC < 0xD7E1)) {
        M2C_FIELD(arg0, M2C_UNK **, 0x138) = &D_80B31D84;
        M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80B33054;
        func_80B313F8();
    }
}

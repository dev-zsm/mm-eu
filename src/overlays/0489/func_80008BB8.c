// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B30910();                            /* extern */
extern u16 D_801E6EFC;
extern M2C_UNK D_80B312F0;
extern M2C_UNK D_80B334EC;

void func_80008BB8(u8 *arg0, M2C_UNK arg1) {
    if (((s32) D_801E6EFC >= 0xD573) && ((s32) D_801E6EFC < 0xD800)) {
        M2C_FIELD(arg0, M2C_UNK **, 0x138) = &D_80B312F0;
        M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80B334EC;
        func_80B30910();
    }
}

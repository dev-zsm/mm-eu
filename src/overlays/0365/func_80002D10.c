// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801A10E8(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_80A5C360(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_80A5EDA4;

void func_80002D10(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x1044) = 0;
    func_801A10E8(0, 0xA);
    func_80A5C360(arg0, 0x13);
    M2C_FIELD(arg0, s16 *, 0x284) = 0xE;
    M2C_FIELD(arg0, M2C_UNK **, 0x278) = &D_80A5EDA4;
}

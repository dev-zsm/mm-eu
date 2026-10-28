// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80A467A4();                            /* extern */
extern M2C_UNK D_80A46A44;

void func_8000048C(u8 *arg0) {
    func_80A467A4();
    M2C_FIELD(arg0, s16 *, 0x3A8) = 0;
    func_800B8C4C(arg0, 0x2949);
    M2C_FIELD(arg0, s16 *, 0x3A4) = 1;
    M2C_FIELD(arg0, M2C_UNK **, 0x18C) = &D_80A46A44;
}

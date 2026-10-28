// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8010E890(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_80ACE87C(M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80ACFF60;

void func_800017A8(u8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0x70) = 2.0f;
    M2C_FIELD(&D_801E6EF0, u8 *, 0x100F) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0x100F) | 0x10);
    func_8010E890(4, 0);
    func_80ACE87C(1, 2);
    M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80ACFF60;
}

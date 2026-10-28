// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80BE3234(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80BE33FC();                            /* extern */
extern M2C_UNK D_80BE3F14;

void func_80000FB0(u8 *arg0) {
    func_80BE33FC();
    M2C_FIELD(arg0, s16 *, 0x2C4) = 0x1E;
    func_80BE3234(arg0, 6, 0x3F800000);
    M2C_FIELD(arg0, s16 *, 0x2DE) = 0;
    M2C_FIELD(arg0, s16 *, 0x2A0) = 2;
    M2C_FIELD(arg0, M2C_UNK **, 0x284) = &D_80BE3F14;
}

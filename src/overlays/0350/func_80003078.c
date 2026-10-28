// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80A418D4();                            /* extern */
extern M2C_UNK D_80A42F70;
extern M2C_UNK D_80A437A8;

void func_80003078(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x190) = &D_80A42F70;
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80A437A8;
    M2C_FIELD(arg0, s16 *, 0x1CC) = 0;
    func_80A418D4();
}

// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1944(s8);                          /* extern */
extern M2C_UNK D_809B3BDC;

void func_80000FB4(u8 *arg0) {
    func_800F1944(M2C_FIELD(arg0, s8 *, 0x38));
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_809B3BDC;
}

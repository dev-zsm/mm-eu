// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1D6C(s16);                         /* extern */
s16 func_800F1E68(s16);                             /* extern */
extern M2C_UNK D_809A7554;

void func_80001634(u8 *arg0, M2C_UNK arg1) {
    func_800F1D6C(M2C_FIELD(arg0, s16 *, 0x430));
    M2C_FIELD(arg0, s16 *, 0x430) = func_800F1E68(M2C_FIELD(arg0, s16 *, 0x430));
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_809A7554;
}

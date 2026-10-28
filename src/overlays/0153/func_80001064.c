// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800FF250(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_8091C644(u8 *);                      /* extern */
M2C_UNK func_8091C720(u8 *);                      /* extern */

void func_80001064(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x1EC) = (s16) (M2C_FIELD(arg0, s16 *, 0x1EC) - 1);
    if (M2C_FIELD(arg0, s16 *, 0x1EC) == 0xE) {
        M2C_FIELD(arg0, s16 *, 0x1F0) = func_800FF250(0xC8, 0x190);
        M2C_FIELD(arg0, s16 *, 0x1F6) = func_800FF250(0x64, 0x1F4);
        M2C_FIELD(arg0, s16 *, 0x1F8) = 0x7D0;
    }
    func_8091C644(arg0);
    if (M2C_FIELD(arg0, s16 *, 0x1EC) < 0) {
        func_8091C720(arg0);
    }
}

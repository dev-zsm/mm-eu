// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8091C644();                            /* extern */
M2C_UNK func_8091C7D4(u8 *);                      /* extern */

void func_80000FB0(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x1EC) = (s16) (M2C_FIELD(arg0, s16 *, 0x1EC) - 1);
    func_8091C644();
    if (M2C_FIELD(arg0, s16 *, 0x1EC) < 0) {
        func_8091C7D4(arg0);
    }
}

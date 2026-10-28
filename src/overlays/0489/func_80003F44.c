// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B297C0();                            /* extern */
M2C_UNK func_80B2C668(u8 *);                      /* extern */

void func_80003F44(u8 *arg0) {
    func_80B297C0();
    M2C_FIELD(arg0, s16 *, 0x2F0) = (s16) (M2C_FIELD(arg0, s16 *, 0x2F0) - 1);
    if (M2C_FIELD(arg0, s16 *, 0x2F0) <= 0) {
        func_80B2C668(arg0);
    }
}

// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800B8D94(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_809447DC();                            /* extern */

void func_80000850(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x1AE) = (s16) (M2C_FIELD(arg0, s16 *, 0x1AE) - 0xC8);
    func_809447DC();
    if (M2C_FIELD(arg0, s16 *, 0x1AE) < 0) {
        func_800B6490(arg0);
        return;
    }
    func_800B8D94(arg0, 0x321F);
}

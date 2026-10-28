// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800B8D94(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80AB1DB8();                            /* extern */

void func_80000CF4(u8 *arg0) {
    func_80AB1DB8();
    if (M2C_FIELD(arg0, s32 *, 0x21C) >= 0x51) {
        func_800B6490(arg0);
        return;
    }
    func_800B8D94(arg0, 0xCF);
}

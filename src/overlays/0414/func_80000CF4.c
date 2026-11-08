// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0414.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800B8D94(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80AB1DB8();                            /* extern */

void func_80000CF4(Actor *thisx) {
    func_80AB1DB8();
    if (M2C_FIELD(thisx, s32 *, 0x21C) >= 0x51) {
        func_800B6490(thisx);
        return;
    }
    func_800B8D94(thisx, 0xCF);
}

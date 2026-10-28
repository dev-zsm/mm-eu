// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801A0070(u8 *, M2C_UNK, u8 *);     /* extern */

void func_80000A48(u8 *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x150) == 2) {
        func_801A0070(arg0 + 0xEC, 0x2843, arg0);
        return;
    }
    func_801A0070(arg0 + 0xEC, 0x2804, arg0);
}

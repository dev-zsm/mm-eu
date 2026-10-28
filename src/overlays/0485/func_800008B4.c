// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFDD8(u8 *, s16, M2C_UNK, M2C_UNK); /* extern */

void func_800008B4(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, u16 *, 0x322) & 0x20) {
        func_800FFDD8(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 3, 0x2AA8);
        return;
    }
    func_800FFDD8(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x32), 3, 0x2AA8);
}

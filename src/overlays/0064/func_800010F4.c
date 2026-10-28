// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFBF8(u8 *, s32, M2C_UNK, M2C_UNK); /* extern */
s32 func_80137070(s32);                             /* extern */
M2C_UNK func_8086E008(u8 *);                      /* extern */
M2C_UNK func_8086E6B0(u8 *);                      /* extern */

void func_800010F4(u8 *arg0, M2C_UNK arg1) {
    if (func_80137070(arg0 + 0x144) != 0) {
        if (M2C_FIELD(arg0, u8 *, 0xB7) == 0) {
            func_8086E6B0(arg0);
        } else {
            M2C_FIELD(arg0, u8 *, 0x2F9) = (u8) (M2C_FIELD(arg0, u8 *, 0x2F9) | 1);
            func_8086E008(arg0);
        }
    }
    func_800FFBF8(arg0 + 0x28, M2C_FIELD(arg0, s32 *, 0xC), 0x3F000000, 0x40A00000);
}

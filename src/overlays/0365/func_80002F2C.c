// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800FFC68(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_800FFCBC(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */

void func_80002F2C(u8 *arg0, M2C_UNK arg1) {
    func_800FFCBC(arg0 + 0x366, 0, 1, 0xF, 0x32);
    func_800FFC68(arg0 + 0xCC, 0x3E99999A, 0x40400000);
    if (M2C_FIELD(arg0, s16 *, 0x366) < 2) {
        func_800B6490(arg0);
    }
}

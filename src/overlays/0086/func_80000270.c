// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8D6C(u8 *, M2C_UNK);             /* extern */
s32 func_800FEC70(s32, M2C_UNK, M2C_UNK);           /* extern */
M2C_UNK func_8016AAF8(s32, s16, s16);               /* extern */
M2C_UNK func_808A7324(u8 *, s32);                 /* extern */

void func_80000270(u8 *arg0, s32 arg1) {
    if (func_800FEC70(arg0 + 0xC0, -0x8000, 0x200) != 0) {
        func_808A7324(arg0, arg1);
    }
    func_800B8D6C(arg0, 0x2098);
    func_8016AAF8(arg1, M2C_FIELD(arg0, s16 *, 0x148), M2C_FIELD(arg0, s16 *, 0xC0));
}

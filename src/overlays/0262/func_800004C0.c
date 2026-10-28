// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
s32 func_800FEE3C(u8 *, M2C_UNK, s32, u8 *);    /* extern */

void func_800004C0(u8 *arg0, M2C_UNK arg1) {
    if (func_800FEE3C(arg0 + 0x5C, 0x3BA3D70A, M2C_FIELD(arg0, s32 *, 0x158), arg0) != 0) {
        func_800B6490(arg0);
    }
}

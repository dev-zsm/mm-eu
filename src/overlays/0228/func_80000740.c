// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEE3C(u8 *, M2C_UNK, M2C_UNK, u8 *); /* extern */
M2C_UNK func_8096923C(u8 *);                      /* extern */

void func_80000740(u8 *arg0, M2C_UNK arg1) {
    func_800FEE3C(arg0 + 0x58, 0x3E3851EB, 0x3B449BA6, arg0);
    func_800FEE3C(arg0 + 0x5C, 0x3D4CCCCD, 0x3B449BA6, arg0);
    M2C_FIELD(arg0, f32 *, 0x60) = (f32) M2C_FIELD(arg0, f32 *, 0x58);
    if (M2C_FIELD(arg0, u16 *, 0x90) & 1) {
        func_8096923C(arg0);
    }
}

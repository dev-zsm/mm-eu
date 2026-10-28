// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8091F978(u8 *);                      /* extern */
M2C_UNK func_8091F9B4();                            /* extern */
M2C_UNK func_809201E4(u8 *);                      /* extern */
extern f32 D_80921994;

void func_80000FA0(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, f32 *, 0x5C) = (f32) (M2C_FIELD(arg0, f32 *, 0x5C) + D_80921994);
    if (M2C_FIELD(arg0, f32 *, 0x250) <= M2C_FIELD(arg0, f32 *, 0x5C)) {
        func_8091F9B4();
        func_8091F978(arg0);
        func_809201E4(arg0);
    }
}

// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B75BE8(u8 *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK D_80B7509C;

void func_80001E20(u8 *arg0) {
    func_80B75BE8(arg0, 0, 1);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80B7509C;
}

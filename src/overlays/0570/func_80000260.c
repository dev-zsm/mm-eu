// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80BB617C(u8 *);                      /* extern */

void func_80000260(u8 *arg0, s16 arg1) {
    func_80BB617C(arg0);
    M2C_FIELD(arg0, s16 *, 0x32C) = arg1;
}

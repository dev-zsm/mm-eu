// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8082D16C(u8 *);                      /* extern */

void func_80000044(u8 *arg0) {
    func_8082D16C(arg0);
    M2C_FIELD(arg0, s8 *, 0xAA5) = 0;
}

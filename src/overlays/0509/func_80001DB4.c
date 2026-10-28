// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */

void func_80001DB4(u8 *arg0) {
    u8 *temp_a0;

    func_800B6490(arg0);
    temp_a0 = M2C_FIELD(arg0, u8 **, 0x2B8);
    if (temp_a0 != NULL) {
        func_800B6490(temp_a0);
    }
}

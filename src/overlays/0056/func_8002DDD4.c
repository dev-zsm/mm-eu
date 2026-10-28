// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8083643C(u8 *, s16, u8 *);         /* extern */

void func_8002DDD4(u8 *arg0, s16 arg1) {
    u8 *temp_a0;

    temp_a0 = M2C_FIELD(arg0, u8 **, 0x1CCC);
    M2C_FIELD(temp_a0, s16 *, 0x4A) = arg1;
    func_8083643C(temp_a0, arg1, arg0);
}

// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_8000125C(u8 *arg0, u8 *arg1) {
    u8 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 *, 0x1EA);
    if (!(temp_v0 & 4) && (M2C_FIELD(arg0, s8 *, 0x1EC) != M2C_FIELD(arg1, s8 *, 0x186E0))) {
        M2C_FIELD(arg0, u8 *, 0x1EA) = (u8) (temp_v0 | 4);
    }
}

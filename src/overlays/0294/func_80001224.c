// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80001224(u8 *arg0) {
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 **, 0x1CCC);
    if ((M2C_FIELD(temp_v0, u8 *, 0x14B) == 1) && (M2C_FIELD(temp_v0, s32 *, 0xA74) & 0x02000000)) {
        return 0;
    }
    return 1;
}

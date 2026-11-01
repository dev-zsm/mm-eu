// FLAGS: -O2 -g3 -mips2
// STATUS: automatic draft, 5/11 instructions differ
#include "types.h"
#include "m2c_compat.h"

void func_800AF464(u8 *arg0) {
    u8 *temp_v0;

    temp_v0 = arg0 + (M2C_FIELD(arg0, s16 *, 0x602) * 0x18);
    *(temp_v0 - 0x18) = M2C_FIELD(temp_v0, u16 *, -0x18) | 2;
}
